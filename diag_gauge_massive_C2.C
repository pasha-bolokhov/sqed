#include <FeynDiagram/fd.h>

#include "localdefs.h"


#define RAD    2.5

/*
 * Diagram "C2", SQED, Massive unbroken SUSY,
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
  xy                     arcpt1 (RAD, 0); arcpt1.rotate(-135);

  xy                     arcpt11(RAD + MLINE_SHIFT, 0); arcpt11.rotate(45);
  xy                     arcpt12(RAD - MLINE_SHIFT, 0); arcpt12.rotate(45);
  xy                     arcpt2 (RAD, 0);               arcpt2.rotate(45);
  xy                     arcpt21(RAD + MLINE_SHIFT, 0); arcpt21.rotate(-45);
  xy                     arcpt22(RAD - MLINE_SHIFT, 0); arcpt22.rotate(-45);
  xy                     arcpt31(0, RAD + MLINE_SHIFT);
  xy                     arcpt32(0, RAD - MLINE_SHIFT);
  /* the ordinary SQED vertex */
  vertex	         v1(fd, -RAD, 0);
  vertex_circlecross     v2(fd,  RAD, 0);
  vertex                 v21(fd,  RAD + MLINE_SHIFT, 0);
  vertex                 v22(fd,  RAD - MLINE_SHIFT, 0);
  vertex		 v11(fd, -RAD - MLINE_SHIFT, 0);
  vertex		 v12(fd, -RAD + MLINE_SHIFT, 0);

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
  xy                     bar2_1 = bar_1; bar2_1.rotate(BAR_ANGLE + DBAR);
  xy                     bar2_2 = bar_2; bar2_2.rotate(BAR_ANGLE + DBAR);
  line_plain             bb2(fd, bar2_1, bar2_2);

  /* photon line propagators */
  line_wiggle            ph1(fd, el, v11), ph2(fd, v21, er);

  line_plain             f11(fd, v11, v21);
  line_plain             f12(fd, v12, v22);
  line_plain             f21(fd, v21, v11);
  line_plain             f22(fd, v22, v12);

  /* stretch it to be an arc */
  f11.arcthru(arcpt11);
  f12.arcthru(arcpt12);
  f21.arcthru(arcpt21);
  f22.arcthru(arcpt22);

  pg.output();
  return 0;
}
