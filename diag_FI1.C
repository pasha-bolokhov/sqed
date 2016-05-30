#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * Stefan's picture
 * Cancellation of FI at one loop, LHS
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5
#define WRAD   0.5
#define RESMSHIFT  0.30

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  fd.line_plain_arrowon.setfalse();
  /* define the left and the right external points */
  xy                     el(-TADPOLELEG, 0), er(6, 0);
  /* the LV vertex */
  xy                     arcpt1(0, RAD);
  xy                     arcpt2(0, -RAD);
  /* the ordinary SQED vertex */
  xy                     vv1(-RAD, 0);
  blob                   v1(fd, vv1, WRAD, WRAD);
  vertex                 v2(fd,  RAD, 0);
  vertex                 fict(fd, -RAD - 0.5, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, fict);

  #define ANG  11
  xy                     l11(RAD, 0), l12(RAD, 0);
  l11.rotate(180 - ANG); l12.rotate(ANG);
  xy                     l21(RAD, 0), l22(RAD, 0);
  l21.rotate(- ANG); l22.rotate( - 180 + ANG);
  line_plain             f1(fd, l11, l12);
  line_plain             f2(fd, l21, l22);

  /* stretch it to be an arc */
  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);

  /* the resummed propagator */
  blob                   b(fd, xy(RAD, 0), WRAD, WRAD);
  line_plain             f0(fd, xy(RAD, RESMSHIFT + -0.01), 
			        xy(RAD, RESMSHIFT + 0.01));
  f0.arrowon.settrue();
  f0.thickness.set(0);
  f0.arrowlen.set(0.37);
  f0.arrowangle.set(35);


  pg.output();
  return 0;
}
