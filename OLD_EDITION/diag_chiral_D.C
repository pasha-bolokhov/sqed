#include <FeynDiagram/fd.h>


/*
 * Diagram "D", SQED, unbroken SUSY,
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
  xy                     arcpt(0, 6);
  /* the double LV vertex */
  vertex_circlecross     v(fd,0,0);
  /* chiral line propagators */
  line_plain             f1(fd, el, v), f2(fd, v, er);
  /* fictitious point to raise the circle */
  vertex                 fict(fd, 0, 0.2);
  /* detach the arrows from them */
  f1.arrowon.setfalse();
  f2.arrowon.setfalse();
  /* the vector superfield line */
  line_wiggle photon1(fd, fict, fict);
  /* stretch it to be an arc */
  photon1.arcthru(arcpt);
#if 0
  photon1.width.set(0.5);
#endif

  pg.output();
  return 0;
}
