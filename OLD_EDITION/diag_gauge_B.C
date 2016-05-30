#include <FeynDiagram/fd.h>


/*
 * Diagram "B", SQED, unbroken SUSY,
 * Gauge sector.
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-6, 0), er(6, 0);
  /* the LV vertex */
  vertex_circlecross     v3(fd, 0, -RAD);
  xy                     arcpt1(0, RAD);
  xy                     arcpt2(RAD, 0); arcpt2.rotate(-45);
  xy                     arcpt3(0, -RAD); arcpt3.rotate(-45);
  /* the ordinary SQED vertex */
  vertex                 v1(fd, -RAD, 0);
  vertex                 v2(fd,  RAD, 0);
  /* photon line propagators */
  line_wiggle            ph1(fd, el, v1), ph2(fd, v2, er);

  line_plain             f1(fd, v1, v2);
  line_plain             f2(fd, v2, v3);
  line_plain             f3(fd, v3, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);
  f3.arcthru(arcpt3);

  pg.output();
  return 0;
}
