#include <FeynDiagram/fd.h>

#include "localdefs.h"



/*
 * Stefan's picture                               _
 * 2-loop fully resummed propagators and multiple DDV
 * vertices
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);


  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  fd.line_plain_arrowon.setfalse();

  /* define the left and the right external points */
  xy                     el(-TADPOLELEG, 0), er(6, 0);
  /* the LV vertex */
  xy                     arcpt2(0, -RAD);
  /* the ordinary SQED vertex */
  xy                     vv1(-RAD, 0);
  blob                   v1(fd, vv1, BRAD, BRAD);
  vertex                 v2(fd,  RAD, 0);
  vertex                 fict(fd, -RAD - 0.5, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, fict);

  xy                     arcpt1(RAD, 0);   arcpt1.rotate(155);
  xy                     l11(RAD, 0), l12(RAD, 0);
  RESM(b2, 135, 1);

  l11.rotate(180 - ANG); l12.rotate(135 + ANG);
  xy                     l21(RAD, 0), l22(RAD, 0);
  l21.rotate(- ANG); l22.rotate( - 180 + ANG);
  line_plain             f1(fd, l11, l12);
  line_plain             f2(fd, xy(RAD, 0).rotate(135 - ANG),
  			        xy(0, RAD));
  vertex_box             vb1(fd, xy(0, RAD)); vb1.fill.setfalse();
  vb1.radius.set(BOXRAD);
  line_plain             f3(fd, xy(0, RAD), 
			    xy(RAD, 0).rotate(ANG));
  f3.arcthru(xy(RAD, 0).rotate(45));
  line_plain             f4(fd, xy(RAD, 0).rotate(-ANG),
    		    xy(0, -RAD));
  f4.arcthru(xy(RAD, 0).rotate(-45));
  vertex_box             vb2(fd, xy(0, -RAD)); vb2.fill.setfalse();
  vb2.radius.set(BOXRAD);
  line_plain             f5(fd, xy(0, -RAD), 
			    xy(RAD, 0).rotate(-135 + ANG));
  RESM(b3, 0, 1);

  f5.arcthru(xy(RAD, 0).rotate(-115));
  //  blob                   b4(fd, xy(RAD, 0).rotate(-135), BRAD, BRAD);
  RESM(b4, -135, 1);
  line_plain             f6(fd, xy(RAD, 0).rotate(-135 - ANG),
			    xy(RAD, 0).rotate(-180 + ANG));
  f6.arcthru(xy(RAD, 0).rotate(-155));

  /* stretch it to be an arc */

  f1.arcthru(arcpt1);
  f2.arcthru(xy(RAD, 0).rotate(115));

  /* the middle photon line */
  line_wiggle            ph2(fd, xy(0, RAD), xy(0, BRAD));
  line_wiggle            ph3(fd, xy(0, -RAD), xy(0, -BRAD));
  blob                   bm(fd, xy(0, 0), BRAD, BRAD);


  pg.output();
  return 0;
}
