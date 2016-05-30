#include <FeynDiagram/fd.h>
#include "localdefs.h"


/*
 * Diagram "B", SQED, broken SUSY,
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
  /* the SB vertex */
  xy                     sb_coord(0, RAD);
  //                         sb_coord.rotate(-45);
  vertex_box             sb(fd, sb_coord); sb.fill.setfalse();
  vertex_cross           sb_cross(fd, sb_coord);
                         sb.radius.scale(SB_RADIUS_SCALE);
                         sb_cross.radius.scale(SB_RADIUS_SCALE);
  /* the LV vertex */
  xy                     lv_coord(0, RAD);
                         lv_coord.rotate(-45);
  vertex_circlecross     lv(fd, lv_coord);

  xy                     arcpt1(RAD, 0); arcpt1.rotate(135);
  xy                     arcpt2(0, RAD); arcpt2.rotate(-20);
  xy                     arcpt3(RAD, 0); arcpt3.rotate(20);
  xy                     arcpt4(0, -RAD);
  /* the ordinary SQED vertex */
  vertex                 v1(fd, -RAD, 0);
  vertex                 v2(fd,  RAD, 0);
  /* photon line propagators */
  line_wiggle            ph1(fd, el, v1), ph2(fd, v2, er);

  line_plain             f1(fd, v1, sb); 
  line_plain             f2(fd, sb, lv); f2.arrowon.setfalse();
  line_plain             f3(fd, lv, v2); f3.arrowon.setfalse();
  line_plain             f4(fd, v2, v1);

  /* stretch it to be an arc */
  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);
  f3.arcthru(arcpt3);
  f4.arcthru(arcpt4);

  pg.output();
  return 0;
}
