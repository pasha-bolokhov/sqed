#include <FeynDiagram/fd.h>
#include "localdefs.h"


#define SB_GAUGE_LIFT1   (0.16 * RAD)

/*
 * Diagram "H", SQED, broken SUSY,
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
  xy              arcpt2(RAD, 0);    arcpt2.rotate(45); arcpt2 += xy(0,RAD);

  arcpt1 += xy(0, SB_GAUGE_LIFT1);
  arcpt2 += xy(0, SB_GAUGE_LIFT1);
  
  /* the SB vertex */
  xy                     sb_coord(0, 2 * RAD + SB_GAUGE_LIFT1);
  vertex_box             sb(fd, sb_coord); sb.fill.setfalse();
  vertex_cross           sb_cross(fd, sb_coord);
                         sb.radius.scale(SB_RADIUS_SCALE);
                         sb_cross.radius.scale(SB_RADIUS_SCALE);

  xy                     lv_coord(0, SB_GAUGE_LIFT1);
  vertex_circlecross     v1(fd, lv_coord);        /* the LV vertex */

  /* photon line propagators */
  line_wiggle            ph1(fd, el, er); ph1.width.scale(0.7);

  line_plain             f1(fd, v1, sb);
  line_plain             f2(fd, sb, v1);

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);

  pg.output();
  return 0;
}
