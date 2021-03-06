#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * A free propagator line with 1 LV insertion
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  fd.line_plain_arrowon.setfalse();
  /* define the left and the right external points */
  xy                     el(-PROPLEN/2.0, 0), er(PROPLEN/2.0, 0);
  vertex_circlecross     v1(fd, 0, 0);

  line_plain             f1(fd, el, v1);
  line_plain             f2(fd, v1, er);


  /* stretch it to be an arc */

  pg.output();
  return 0;
}
