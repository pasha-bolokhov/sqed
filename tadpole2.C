#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * A tadpole with 2 LV vertices
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  fd.line_plain_arrowon.setfalse();
  /* define the left and the right external points */
  xy                     el(-TADPOLELEG, 0), er(6, 0);
  /* the LV vertex */
  xy                     arcpt1(0, RAD);  arcpt1.rotate(45);
  xy                     arcpt2(0, -RAD);
  xy                     arcpt3(RAD, 0);
  /* the ordinary SQED vertex */
  vertex_circlecross     v1(fd, -RAD, 0);
  vertex_circlecross     v3(fd,  0, RAD);
  vertex                 fict(fd, -RAD - 0.5, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, fict);

  line_plain             f1(fd, v1, v3);
  line_plain             f3(fd, v3, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f3.arcthru(arcpt3);

  pg.output();
  return 0;
}
