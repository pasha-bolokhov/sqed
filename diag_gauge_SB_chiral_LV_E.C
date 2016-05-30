#include <FeynDiagram/fd.h>
#include "localdefs.h"


/*
 * Diagram "E", SQED, broken SUSY,
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

  vertex_box             sb(fd, sb_coord); sb.fill.setfalse();
  vertex_cross           sb_cross(fd, sb_coord);
                         sb.radius.scale(SB_RADIUS_SCALE);
                         sb_cross.radius.scale(SB_RADIUS_SCALE);

  /* the ordinary SQED vertex */
  vertex                 v1(fd, -RAD, 0);

  xy                     arcpt1(RAD, 0); arcpt1.rotate(135);
  xy                     arcpt2(RAD, 0); arcpt2.rotate(45);
  xy                     arcpt3(RAD, 0); arcpt3.rotate(-90);

  /* the LV vertex */
  vertex_circlecross     v2(fd,  RAD, 0);
  /* photon line propagators */
  line_wiggle            ph1(fd, el, v1), ph2(fd, v2, er);

  line_plain             f1(fd, v1, sb); 
  line_plain             f2(fd, sb, v2); 
  line_plain             f3(fd, v2, v1); 

  /* stretch it to be an arc */
  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);
  f3.arcthru(arcpt3);

  pg.output();
  return 0;
}
