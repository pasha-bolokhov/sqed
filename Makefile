

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

CHIRAL_DIAGS_SB_PS = $(patsubst %, %.ps, $(CHIRAL_DIAGS_SB))

CHIRAL_DIAGS_SB_C = $(patsubst %, %.C, $(CHIRAL_DIAGS_SB))

CHIRAL_DIAGS_SB_BIN = $(patsubst %, %.out, $(CHIRAL_DIAGS_SB))

##
## Gauge SB diagrams (SB still in chiral sector)
##
GAUGE_DIAGS_SB_NAMES = A  B  C  D  E \
		       A1 B1 C1 D1 E1 \
                       F  G  H \

GAUGE_DIAGS_SB = $(patsubst %, diag_gauge_SB_chiral_LV_%, \
                               $(GAUGE_DIAGS_SB_NAMES))

GAUGE_DIAGS_SB_PS = $(patsubst %, %.ps, $(GAUGE_DIAGS_SB))

GAUGE_DIAGS_SB_C = $(patsubst %, %.C, $(GAUGE_DIAGS_SB))

GAUGE_DIAGS_SB_BIN = $(patsubst %, %.out, $(GAUGE_DIAGS_SB))

##
## Gauge Massive SUSY diagrams
##
GAUGE_DIAGS_MASS_NAMES = A1 A2 A3 B1 B2 B3 C1 C2 E1

GAUGE_DIAGS_MASS = $(patsubst %, diag_gauge_massive_%, \
				$(GAUGE_DIAGS_MASS_NAMES))

GAUGE_DIAGS_MASS_PS = $(patsubst %, %.ps, $(GAUGE_DIAGS_MASS))

GAUGE_DIAGS_MASS_C = $(patsubst %, %.C, $(GAUGE_DIAGS_MASS))

GAUGE_DIAGS_MASS_BIN = $(patsubst %, %.out, $(GAUGE_DIAGS_MASS))

##
## Pictures with Tadpoles
## 
TAD_DIAGS = tadpole tadpole1 tadpole2 tadpole1d tadpole1r \
            fullprop freeprop \
	    freeprop1LV freeprop2LV freeprop2LV1 freeprop1LV1 \
	    fulltadpole fulltadpole1 \
	    vertex vertex1

TAD_DIAGS_PS = $(patsubst %, %.ps, $(TAD_DIAGS))

TAD_DIAGS_C = $(patsubst %, %.C, $(TAD_DIAGS))

TAD_DIAGS_BIN = $(patsubst %, %.out, $(TAD_DIAGS))

##
## Stefan's pictures
## 
STF_DIAGS = diag_resmprop diag_inter1 diag_inter2 diag_resum1 diag_resum2 \
	    diag_FI1 diag_FI2 diag_selfenergy \
	    diag_2loop1 diag_2loop2 diag_2loop3 diag_2loop4

STF_DIAGS_PS = $(patsubst %, %.ps, $(STF_DIAGS))

STF_DIAGS_C = $(patsubst %, %.C, $(STF_DIAGS))

STF_DIAGS_BIN = $(patsubst %, %.out, $(STF_DIAGS))


ALL_PICS = $(CHIRAL_DIAGS_PS) $(GAUGE_DIAGS_PS) $(CHIRAL_DIAGS_SB_PS) \
	$(GAUGE_DIAGS_SB_PS) $(GAUGE_DIAGS_MASS_PS) $(TAD_DIAGS_PS) \
	$(STF_DIAGS_PS)

ALL_BINS = $(CHIRAL_DIAGS_BIN) $(GAUGE_DIAGS_BINS) $(CHIRAL_DIAGS_SB_BIN) \
	$(GAUGE_DIAGS_SB_BIN) $(GAUGE_DIAGS_MASS_BIN) $(TAD_DIAGS_BIN) \
	$(STF_DIAGS_BIN)


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
