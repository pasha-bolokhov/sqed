#include <FeynDiagram/fd.h>

#include "localdefs.h"


#define BOX(name, pos)				\
   vertex_box             name(fd, pos);	\
   name.radius.set(BOXRAD);			\
   name.fill.setfalse();
  
#define LINE(name, ang1, ang2)				\
    line_plain       name(fd, xy(RAD, 0).rotate(ang1),	\
    		      xy(RAD, 0).rotate(ang2));		\
    name.arcthru(xy(RAD, 0).rotate((ang1 + ang2)/2.0));

/*
 * Stefan's picture                               _
 * 2-loop fully resummed propagators and multiple DDV
 * vertices, 
 * after some manipulations, picture 3
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
  vertex                 fict(fd, -RAD - 0.5, 0);   /* for a nicer picture */
  /* photon line propagators */
  line_wiggle            ph1(fd, el, xy(-RAD, 0));

  LINE(f1, 180, ANG);
  RESM(b1, 0, 1);
  LINE(f2, -ANG, -90);
  BOX(v1, xy(0, -RAD));
  LINE(f3, -90, -135 + ANG);
  RESM(b2, -135, 1);
  LINE(f4, -135 - ANG, -180);


  /* the middle photon line */
  blob         bm(fd, xy(0, -RAD + BOXRAD + BRAD), BOXRAD, BOXRAD);
  BOX(v2, xy(0, -RAD + BOXRAD + 2*BRAD + BOXRAD));
  line_wiggle  ph2(fd, xy(0, RAD),
		   xy(0, -RAD + BOXRAD + 2*BRAD + BOXRAD*2));

  //line_wiggle            ph2(fd, xy(RAD, 0), xy(BRAD, 0));
  //  line_wiggle            ph3(fd, xy(-RAD, 0), xy(-BRAD, 0));
  //  blob                   bm(fd, xy(0, 0), BRAD, BRAD);


  pg.output();
  return 0;
}
