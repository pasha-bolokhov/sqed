#include <FeynDiagram/fd.h>


/*
 * Diagram "D", SQED, unbroken SUSY,
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
  xy                     arcpt1(0, RAD);
  xy                     arcpt2(0, -RAD);
  /* the ordinary SQED vertex */
  vertex                 v1(fd, -RAD, 0);
  vertex_circlecross     v2(fd,  RAD, 0);
  vertex                 fict(fd, RAD + 0.5, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, v1), ph2(fd, fict, er);

  line_plain             f1(fd, v1, v2);
  line_plain             f2(fd, v2, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);

  pg.output();
  return 0;
}
