#include <FeynDiagram/fd.h>
#include "localdefs.h"


/*
 * Diagram "C", SQED, broken SUSY,
 * Chiral sector.
 */
main()
{
  page                  pg;
  FeynDiagram           fd(pg);

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                    el(-7, 0), er(7, 0);
  /* the upper point of the arc */
  xy                    arcpt(0, 4);
  /* the left ordinary SQED vertex */
  vertex                v1(fd, -4, 0);
  /* the middle SB vertex */
  vertex_box            sb(fd,  0, 0); sb.fill.setfalse();
  vertex_cross          sb1(fd, 0, 0); 
                        sb.radius.scale(SB_RADIUS_SCALE);
			sb1.radius.scale(SB_RADIUS_SCALE);
  /* the right LV vertex */
  vertex_circlecross    v2(fd, 4, 0);
  /* chiral line propagators */
  line_plain            f1(fd, el, v1), 
                        f2(fd, v1, v2), f3(fd, v2, er);
  /* detach the arrows from them */
  f1.arrowon.setfalse();
  f2.arrowon.setfalse();
  f3.arrowon.setfalse();
  /* the vector superfield line */
  line_wiggle photon1(fd, v1, v2);
  /* stretch it to be an arc */
  photon1.arcthru(arcpt);

  pg.output();
  return 0;
}
