#include <FeynDiagram/fd.h>


/*
 * Diagram "T" (3-tensor operator), SQED, unbroken SUSY,
 * Chiral sector.
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-7, 0), er(7, 0);
  /* the upper point of the arc */
  xy                     arcpt(0, 4);
  vertex_box             LV(fd, 0, 4);  LV.fill.setfalse();
  /* the left ordinary SQED vertex */
  vertex                 v1(fd, -4, 0);
  /* the right ordinary SQED vertex */
  vertex                 v2(fd,4,0);
  /* chiral line propagators */
  line_plain             f1(fd, el, v1), f2(fd, v1, v2), 
                         f3(fd, v2, er);
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
