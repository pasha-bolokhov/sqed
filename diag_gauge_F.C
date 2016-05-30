#include <FeynDiagram/fd.h>
#include "localdefs.h"


#define GAUGE_LIFT1   (0.16 * RAD)

/*
 * Diagram "F", SQED, unbroken SUSY,
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

  xy              arcpt1(RAD, 0);    arcpt1.rotate(90); arcpt1 += xy(0,RAD);

  arcpt1 += xy(0, GAUGE_LIFT1);

  /* the LV vertex */
  xy                     lv_coord(0, GAUGE_LIFT1);
  vertex_circlecross     v1(fd, lv_coord);        

  /* photon line propagators */
  line_wiggle            ph1(fd, er, el); // ph1.width.scale(0.7);

  line_plain             f1(fd, v1, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);

  pg.output();
  return 0;
}
