#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * Stefan's picture
 * Cancellation of FI at one loop, RHS
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-TADPOLELEG, 0), er(6, 0);
  /* the LV vertex */
  xy                     arcpt1(RAD, 0);
  xy                     arcpt2(0, -RAD);
  /* the ordinary SQED vertex */
  vertex                 v1(fd, xy(-RAD, 0));
  v1.radius.set(0.3);
  vertex                 v2(fd,  RAD, 0);
  vertex                 fict(fd, -RAD, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, fict);

  line_plain             f1(fd, v1, v1);
  f1.arrowon.settrue();
  f1.arrowposition.set(0.50);
  f1.arrowlen.set(0.37);
  f1.arrowangle.set(35);
  //  line_plain             f2(fd, v2, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1, 1);   /* counter-clockwise */
  //  f2.arcthru(arcpt2);

  pg.output();
  return 0;
}
