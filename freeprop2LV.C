#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * A free propagator line with 2 LV insertions
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    2.5

#define LEN    7.2


  double  r = fd.vertex_radius_large.get();

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);

  fd.line_plain_arrowon.setfalse();
  /* define the left and the right external points */
  xy                     el(-LEN / 2.0, 0), 
                         er( LEN / 2.0, 0);
  vertex_circlecross     v1(fd, -LEN / 6.0 - r / 2.0, 0);
  vertex_circlecross     v2(fd,  LEN / 6.0 + r / 2.0, 0);

  line_plain             f1(fd, el, v1);
  line_plain             f2(fd, v1, v2);
  line_plain             f3(fd, v2, er);

  pg.output();
  return 0;
}
