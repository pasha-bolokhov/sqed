#include <FeynDiagram/fd.h>


/*
 * Resummed propagator
 * Stefan's picture
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5
#define WRAD   0.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  blob                   v1(fd, xy(0, 0), WRAD, WRAD);

  /* define the left and the right external points */
  xy                     el(-3, 0), er(3, 0);

  /* photon line propagators */
  line_plain             f1(fd, el, v1.location(180));
  line_plain             f2(fd, er, v1.location(0));
  f1.arrowon.setfalse();
  f2.arrowon.setfalse();
  line_plain             f0(fd, xy(0.30 + -0.01, 0), xy(0.30 + 0.01, 0));
  f0.thickness.set(0);
  f0.arrowlen.set(0.37);
  f0.arrowangle.set(35);

  pg.output();
  return 0;
}
