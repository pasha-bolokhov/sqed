#include <FeynDiagram/fd.h>
#include "localdefs.h"


/*
 * Diagram "E", SQED, unbroken SUSY,
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

  xy              arcpt1(RAD, 0);    arcpt1.rotate(180); arcpt1 += xy(0,RAD);
  xy              arcpt2(RAD, 0);                        arcpt2 += xy(0,RAD);

  arcpt1 += xy(0, GAUGE_LIFT);
  arcpt2 += xy(0, GAUGE_LIFT);
  
  /* the LV vertex */
  xy                     lv_coord(0, 2 * RAD + GAUGE_LIFT);
  vertex_circlecross     lv(fd, lv_coord);

  vertex_dot             v1(fd, 0, 
			    GAUGE_LIFT);  /* the ordinary SQED vertex */
  v1.radius.scale(1.7);

  /* photon line propagators */
  line_wiggle            ph1(fd, el, er); ph1.width.scale(0.7);

  line_plain             f1(fd, v1, lv);
  line_plain             f2(fd, lv, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);

  pg.output();
  return 0;
}
