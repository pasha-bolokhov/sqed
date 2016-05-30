#include <FeynDiagram/fd.h>


/*
 * Resummation vertex + prop, LHS
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

  blob                   v1(fd, xy(0, 0), BRAD, BRAD);

  /* define the left and the right external points */
  xy                     el(-3, 0), er(3, 0);
  xy                     ln11(BRAD, 0),   ln12(WLEN, 0);
  ln11.rotate(40);  ln12.rotate(40);
  xy                     ln21(BRAD, 0),   ln22(WLEN, 0);
  ln21.rotate(90);  ln22.rotate(90);
  xy                     ln31(BRAD, 0),   ln32(WLEN, 0);
  ln31.rotate(140);  ln32.rotate(140);
  line_wiggle          w1(fd, ln11, ln12);
  line_wiggle          w2(fd, ln21, ln22);
  line_wiggle          w3(fd, ln31, ln32);

  /* resummed propagator */
  blob                   b(fd, xy(4, 0), BRAD, BRAD);
  line_plain             f0(fd, xy(4  +  
                                   0.30 + -0.01, 0), 
                                xy(4  + 
                                   0.30 + 0.01, 0));
  f0.thickness.set(0);
  f0.arrowlen.set(0.37);
  f0.arrowangle.set(35);


  /* chiral line propagators */
  line_plain             f1(fd, el, v1.location(180));
  line_plain             f2(fd, v1.location(0), b.location(180));
  line_plain             f3(fd, b.location(0), xy(6.5,0));
  f1.arrowon.setfalse();
  f2.arrowon.setfalse();
  f3.arrowon.setfalse();

  pg.output();
  return 0;
}
