#ifndef __LOCALDEFS_H__
#define __LOCALDEFS_H__

#define GAUGE_LIFT        (0.12 * RAD)
#define GAUGE_LIFT1       (0.16 * RAD)
#define GAUGE_LIFT2       (0.20 * RAD)

#define SB_RADIUS_SCALE    0.8

#define SB_GAUGE_LIFT     (0.12 * RAD)
#define SB_GAUGE_LIFT1   (0.16 * RAD)


#define MLINE_SHIFT      0.14

#define BAR_LEN          0.6

#define BAR_ANGLE        14.0    /* degrees */
#define DBAR             5.0     /* degrees */

/* smaller bar */
#define BARS_LEN          0.5
#define BARS_ANGLE        11.0    /* degrees */

/* length of the tadpole photon leg */
#define TADPOLELEG        7.0

/* length of the propagator */
#define PROPLEN           6.0

/* width of the full propagator */
#define FULLPROPTHICK     0.30

/* text y shift downwards from the propagator vertices */
#define TEXTYSHIFT        1.3

/* length of the wiggled line in the SQED vertex */
#define VERTEXHEIGHT      3.0


/***********************************
 *   Stuff for Stefan's pictures   *
 ***********************************/

/* a resummed propagator */
/* 
 *  'clock' must be 1 for clockwise,
 *                 -1 for counterclockwise
 */
#define RESM(name, ang,  clock)						\
  blob                   name(fd, xy(RAD, 0).rotate(ang), BRAD, BRAD);	\
  line_plain             b##name(fd,					\
				 xy(RAD, clock*				\
				    (-RESMSHIFT + 0.01)).rotate(ang),	\
				 xy(RAD, clock*				\
                                         (-RESMSHIFT + -0.01)).rotate(ang)); \
  b##name.arrowon.settrue();						\
  b##name.thickness.set(0);						\
  b##name.arrowlen.set(0.37);                                           \
  b##name.arrowangle.set(35);

#define RAD    2.5        /* radius of the loop */
#define BRAD   0.5        /* radius of the blob */
#define BOXRAD 0.4        /* size of the box */


#define ANG  (atan(BRAD/RAD)*180.0/3.141592653) /* the angular size of the radius of the blob */

  /* shift of the arrow in the circle in the resummed propagator */
#define RESMSHIFT  0.30



#endif /* __LOCALDEFS_H__ */
