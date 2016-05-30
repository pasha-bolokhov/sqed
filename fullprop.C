#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * A full propagator line
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-PROPLEN/2.0, 0), er(PROPLEN/2.0, 0);

  line_plain             f1(fd, el, er);

  f1.thickness.set(FULLPROPTHICK);
  f1.arrowon.setfalse();


  /* stretch it to be an arc */

  pg.output();
  return 0;
}
