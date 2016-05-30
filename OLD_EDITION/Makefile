

##
## Chiral Diagrams
##
CHIRAL_DIAGS_NAMES = A B C D E T

CHIRAL_DIAGS = $(patsubst %, diag_chiral_%, $(CHIRAL_DIAGS_NAMES)) 

CHIRAL_DIAGS_PS = $(patsubst %, %.ps, $(CHIRAL_DIAGS))

CHIRAL_DIAGS_C = $(patsubst %, %.C, $(CHIRAL_DIAGS))

CHIRAL_DIAGS_BIN = $(patsubst %, %.out, $(CHIRAL_DIAGS))

##
## Gauge Diagrams
##
GAUGE_DIAGS_NAMES = A B C D E F

GAUGE_DIAGS = $(patsubst %, diag_gauge_%, $(GAUGE_DIAGS_NAMES))

GAUGE_DIAGS_PS = $(patsubst %, %.ps, $(GAUGE_DIAGS))

GAUGE_DIAGS_C = $(patsubst %, %.C, $(GAUGE_DIAGS))

GAUGE_DIAGS_BIN = $(patsubst %, %.out, $(GAUGE_DIAGS))

##
## Chiral SB diagrams
##
CHIRAL_DIAGS_SB_NAMES = A B C D

CHIRAL_DIAGS_SB = $(patsubst %, diag_chiral_SB_chiral_LV_%, \
                                $(CHIRAL_DIAGS_SB_NAMES))

CHIRAL_DIAGS_SB += diag_chiral_SB_gauge_LV

CHIRAL_DIAGS_PS = $(patsubst %, %.ps, $(CHIRAL_DIAGS_SB))

CHIRAL_DIAGS_C = $(patsubst %, %.C, $(CHIRAL_DIAGS_SB))

CHIRAL_DIAGS_BIN = $(patsubst %, %.out, $(CHIRAL_DIAGS_SB))

##
## Gauge SB diagrams (SB still in chiral sector)
##
GAUGE_DIAGS_SB_NAMES = A  B  C  D  E \
		       A1 B1 C1 D1 E1 \
                       F  G  H

GAUGE_DIAGS_SB = $(patsubst %, diag_gauge_SB_chiral_LV_%, \
                               $(GAUGE_DIAGS_SB_NAMES))

GAUGE_DIAGS_PS = $(patsubst %, %.ps, $(GAUGE_DIAGS_SB))

GAUGE_DIAGS_C = $(patsubst %, %.C, $(GAUGE_DIAGS_SB))

GAUGE_DIAGS_BIN = $(patsubst %, %.out, $(GAUGE_DIAGS_SB))



ALL_PICS = $(CHIRAL_DIAGS_PS) $(GAUGE_DIAGS_PS) $(CHIRAL_DIAGS_PS)

ALL_BINS = $(CHIRAL_DIAGS_BIN) $(GAUGE_DIAGS_BINS) $(CHIRAL_DIAGS_BIN)


lv_sqed.ps: lv_sqed.dvi
	dvips -o $@ $<

lv_sqed.dvi: lv_sqed.tex
	latex lv_sqed.tex && latex lv_sqed.tex

pics: $(ALL_PICS)


%.ps: %.out
	./$< > $@


%.out: %.C localdefs.h
	./compile $< -o $@

clean:
	rm -f $(ALL_BINS)

clean_pics:
	rm -f $(ALL_PICS)
