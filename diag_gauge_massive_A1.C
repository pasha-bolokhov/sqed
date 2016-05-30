#include <FeynDiagram/fd.h>

#include "localdefs.h"


#define RAD    2.5


///
///void put_bar(double angle)
///{
///  // bar 
///  xy                     bar1_1 = bar_1; bar1_1.rotate(angle);
///  xy                     bar1_2 = bar_2; bar1_2.rotate(angle);
///  line_plain             bb1(fd, bar1_1, bar1_2);
///}
///

/*
 * Diagram "A1", SQED, Massive unbroken SUSY,
 * Gauge sector.
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

  fd.line_plain_arrowon.setfalse();

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-6, 0), er(6, 0);
  /* the LV vertex */
  vertex_circlecross     v3(fd, 0, RAD);
  xy                     arcpt11(RAD + MLINE_SHIFT, 0); arcpt11.rotate(135);
  xy                     arcpt12(RAD - MLINE_SHIFT, 0); arcpt12.rotate(135);
  xy                     arcpt2(RAD, 0); arcpt2.rotate(45);
  xy                     arcpt31(0, -RAD - MLINE_SHIFT);
  xy                     arcpt32(0, -RAD + MLINE_SHIFT);
  /* the ordinary SQED vertex */
  vertex                 v2(fd,  RAD, 0);
  vertex                 v21(fd,  RAD + MLINE_SHIFT, 0);
  vertex                 v22(fd,  RAD - MLINE_SHIFT, 0);
  vertex		 v11(fd, -RAD - MLINE_SHIFT, 0);
  vertex		 v12(fd, -RAD + MLINE_SHIFT, 0);
  vertex                 v31(fd, 0, RAD + MLINE_SHIFT);
  vertex                 v32(fd, 0, RAD - MLINE_SHIFT);

  /* conjugate bars */
  xy                     bar_1(RAD + BAR_LEN / 2.0, 0);
  xy                     bar_2(RAD - BAR_LEN / 2.0, 0);
  /* smaller bar: for single line */
  xy                     bars_1(RAD + BARS_LEN / 2.0, 0);
  xy                     bars_2(RAD - BARS_LEN / 2.0, 0);

  // bar 1
  xy                     bar1_1 = bar_1; bar1_1.rotate(180 - BAR_ANGLE);
  xy                     bar1_2 = bar_2; bar1_2.rotate(180 - BAR_ANGLE);
  line_plain             bb1(fd, bar1_1, bar1_2);

  // bar 2
  xy                     bar2_1 = bar_1; bar2_1.rotate(90 + BAR_ANGLE + DBAR);
  xy                     bar2_2 = bar_2; bar2_2.rotate(90 + BAR_ANGLE + DBAR);
  line_plain             bb2(fd, bar2_1, bar2_2);

  // bar 3
  xy                     bar3_1 = bars_1; bar3_1.rotate(BARS_ANGLE);
  xy                     bar3_2 = bars_2; bar3_2.rotate(BARS_ANGLE);
  line_plain             bb3(fd, bar3_1, bar3_2);

  /* photon line propagators */
  line_wiggle            ph1(fd, el, v11), ph2(fd, v21, er);

  line_plain             f11(fd, v11, v31);
  line_plain             f12(fd, v12, v32);
  line_plain             f2(fd, v3, v2);
  line_plain             f31(fd, v21, v11);
  line_plain             f32(fd, v22, v12);

  /* stretch it to be an arc */
  f11.arcthru(arcpt11);
  f12.arcthru(arcpt12);
  f2.arcthru(arcpt2);
  f31.arcthru(arcpt31);
  f32.arcthru(arcpt32);

  pg.output();
  return 0;
}
