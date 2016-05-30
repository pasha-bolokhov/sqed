#include <FeynDiagram/fd.h>


/*
 * Resummation vertex + prop, RHS
 * Stefan's picture
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

#define WLEN   3.0

#define BRAD   0.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  vertex                 v1(fd, xy(0, 0));
  v1.radius.set(0.3);

  /* define the left and the right external points */
  xy                     el(-3, 0), er(3, 0);
#if 0
  xy                     ln11(0.30, 0),   ln12(WLEN, 0);
  ln11.rotate(50);  ln12.rotate(50);
  xy                     ln21(0.30, 0),   ln22(WLEN, 0);
  ln21.rotate(90);  ln22.rotate(90);
  xy                     ln31(0.30, 0),   ln32(WLEN, 0);
  ln31.rotate(130);  ln32.rotate(130);

  line_wiggle          w1(fd, ln11, ln12);
  line_wiggle          w2(fd, ln21, ln22);
  line_wiggle          w3(fd, ln31, ln32);
#endif

  line_wiggle          w1(fd, xy(WLEN, 0).rotate(45), xy(0,0));
  line_wiggle          w2(fd, xy(0, 0.30), xy(0, WLEN));
  line_wiggle          w3(fd, xy(0,0), xy(WLEN, 0).rotate(130));

  /* chiral line propagators */
  line_plain             f1(fd, el, xy(0,0));
  line_plain             f2(fd, xy(0,0), xy(6.5, 0));
  f1.arrowon.setfalse();
  f2.arrowon.settrue();
  f2.arrowposition.set(0.6);
  f2.arrowlen.set(0.37);
  f2.arrowangle.set(35);

  pg.output();
  return 0;
}
