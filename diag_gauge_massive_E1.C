#include <FeynDiagram/fd.h>
#include "localdefs.h"

/*
 * Diagram "E1", SQED, Massive unbroken SUSY,
 * Gauge sector.
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5
  fd.line_plain_arrowon.setfalse();

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-6, 0), er(6, 0);

  xy              arcpt1(RAD, 0);    arcpt1.rotate(180); arcpt1 += xy(0,RAD);
  xy              arcpt2(RAD, 0);                        arcpt2 += xy(0,RAD);
  xy              arcpt11(RAD + MLINE_SHIFT, 0);    
                                 arcpt11.rotate(180); arcpt11 += xy(0,RAD);
  xy              arcpt12(RAD - MLINE_SHIFT, 0);    
                                 arcpt12.rotate(180); arcpt12 += xy(0,RAD);
  xy              arcpt21(RAD + MLINE_SHIFT, 0);         arcpt21 += xy(0,RAD);
  xy              arcpt22(RAD - MLINE_SHIFT, 0);         arcpt22 += xy(0,RAD);
  

  arcpt1 += xy(0, GAUGE_LIFT2);
  arcpt2 += xy(0, GAUGE_LIFT2);
  
  /* the LV vertex */
  xy                     lv_coord(0, 2 * RAD + GAUGE_LIFT2);
  vertex_circlecross     lv(fd, lv_coord);
  vertex                 lv1(fd, 0, 2 * RAD + MLINE_SHIFT + GAUGE_LIFT2);
  vertex                 lv2(fd, 0, 2 * RAD - MLINE_SHIFT + GAUGE_LIFT2);

  vertex                 v0(fd, 0, 0);
  vertex_dot             v1(fd, 0, 
			    GAUGE_LIFT2);  /* the ordinary SQED vertex */
  vertex_dot             v11(fd, 0, 
			    -MLINE_SHIFT + GAUGE_LIFT2); 
  vertex_dot             v12(fd, 0, 
			    +MLINE_SHIFT + GAUGE_LIFT2); 
  v1.radius.scale(1.7);

  /* conjugate bars */
  xy                     bar_1(RAD + BAR_LEN / 2.0, 0);
  xy                     bar_2(RAD - BAR_LEN / 2.0, 0);
  /* smaller bar: for single line */
  xy                     bars_1(RAD + BARS_LEN / 2.0, 0);
  xy                     bars_2(RAD - BARS_LEN / 2.0, 0);

  // bar 1
  xy                     bar1_1 = bar_1; bar1_1.rotate(90 + BAR_ANGLE + 2 * DBAR);
  bar1_1 += xy(0, RAD + GAUGE_LIFT2);
  xy                     bar1_2 = bar_2; bar1_2.rotate(90 + BAR_ANGLE + 2 * DBAR);
  bar1_2 += xy(0, RAD + GAUGE_LIFT2);
  line_plain             bb1(fd, bar1_1, bar1_2);

  // bar 2
  xy                     bar2_1 = bar_1; bar2_1.rotate(-90 - BAR_ANGLE - DBAR);
  bar2_1 += xy(0, RAD + GAUGE_LIFT2);
  xy                     bar2_2 = bar_2; bar2_2.rotate(-90 - BAR_ANGLE - DBAR);
  bar2_2 += xy(0, RAD + GAUGE_LIFT2);
  line_plain             bb2(fd, bar2_1, bar2_2);


  /* photon line propagators */
  line_wiggle            ph1(fd, er, el); //ph1.width.scale(0.7);
  //  line_wiggle            ph1(fd, el, v0); //ph1.width.scale(0.7);
  //  line_wiggle            ph2(fd, v0, er); //ph1.width.scale(0.7);

  line_plain             f11(fd, v11, lv1);
  line_plain             f12(fd, v12, lv2);
  line_plain             f21(fd, lv1, v11);
  line_plain             f22(fd, lv2, v12);

  /* stretch it to be an arc */

  f11.arcthru(arcpt11);
  f12.arcthru(arcpt12);
  f21.arcthru(arcpt21);
  f22.arcthru(arcpt22);

  pg.output();
  return 0;
}
