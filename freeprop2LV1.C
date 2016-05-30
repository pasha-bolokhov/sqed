#include <FeynDiagram/fd.h>

#include "localdefs.h"

/*
 * A free propagator line with 2 LV insertions,
 * the right line a bit shorter
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
                         er( LEN / 2.0 - 0.9, 0);
  xy                     p1(-LEN / 6.0 - r / 2.0, 0);
  xy                     p2( LEN / 6.0 + r / 2.0, 0);
  vertex_circlecross     v1(fd, p1);
  vertex_circlecross     v2(fd, p2); 

  line_plain             f1(fd, el, v1);
  line_plain             f2(fd, v1, v2);
  line_plain             f3(fd, v2, er);

  /* put subscripts */
  text        t1(fd, "1", p1 - xy(0, TEXTYSHIFT), 1.0, 1.0);
  text        t2(fd, "2", p2 - xy(0, TEXTYSHIFT), 0.6, 1.0);

  pg.output();
  return 0;
}
