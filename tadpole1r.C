#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * A tadpole with 1 LV vertex on the electron line
 * located on the opposite side to the QED vertex
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
  xy                     arcpt1(RAD, 0);    arcpt1.rotate( 90);
  xy                     arcpt2(RAD, 0);    arcpt2.rotate(-90);
  /* the ordinary SQED vertex */
  vertex_circlecross     v1(fd, RAD, 0);
  vertex                 v2(fd, -RAD, 0);
  vertex                 fict(fd, -RAD - 0.5, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, v2);

  line_plain             f1(fd, v2, v1);
  line_plain             f2(fd, v1, v2);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);

  pg.output();
  return 0;
}
