#include <FeynDiagram/fd.h>


/*
 * Stefan's diagram          _
 * A chiral self-energy with DDV vertex and
 * a LV on the gauge line
 */
main()
{
  page                   pg;
  FeynDiagram            fd(pg);

#define RAD    3.0

  fd.line_thickness.set(0.15);
  fd.vertex_thickness.set(0.15);
  /* define the left and the right external points */
  xy                     el(-6.5, 0), er(6.5, 0);
  /* the LV vertex */
  vertex_circlecross     v3(fd, 0, RAD);
  xy                     arcpt1(RAD, 0); arcpt1.rotate(135);
  xy                     arcpt2(RAD, 0); arcpt2.rotate(45);
  xy                     arcpt3(0, -RAD);
  /* the ordinary SQED vertex */
  vertex_circlecross     v1(fd, -RAD, 0);
  vertex_circlecross     v2(fd,  RAD, 0);
  /* photon line propagators */
  line_plain             ph1(fd, el, v1), ph2(fd, v2, er);
  ph1.arrowon.setfalse();  ph2.arrowon.setfalse();

  line_wiggle            f1(fd, v3, v1);
  line_wiggle            f2(fd, v2, v3);
  line_plain             f3(fd, v1, v2);

  /* stretch it to be an arc */
  f1.arcthru(arcpt1);
  f2.arcthru(arcpt2);
  f3.arcthru(arcpt3);

  pg.output();
  return 0;
}
