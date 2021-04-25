AM_CFLAGS = -I$(top_srcdir)/src/ -I$(srcdir)/
AM_LDFLAGS = -L$(top_builddir)/src/ -lHWFbasis -lm
check_PROGRAMS = 
dist_noinst_SCRIPTS =


#########
# n = 1 #
#########
check_PROGRAMS += HWF_n1_l0_m0
		
HWF_n1_l0_m0_SOURCES = $(srcdir)/HWF_n1_l0_m0.c ref-HWF.c
HWF_n1_l0_m0_CFLAGS  = $(AM_CFLAGS)
HWF_n1_l0_m0_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += HWF_n1_l0_m0.sh

#########
# n = 2 #
#########
check_PROGRAMS += HWF_n2_l0_m0
    
HWF_n2_l0_m0_SOURCES = $(srcdir)/HWF_n2_l0_m0.c ref-HWF.c
HWF_n2_l0_m0_CFLAGS  = $(AM_CFLAGS)
HWF_n2_l0_m0_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += HWF_n2_l0_m0.sh

check_PROGRAMS += HWF_n2_l1_m0 \
		  HWF_n2_l1_mm1 \
		  HWF_n2_l1_mp1

HWF_n2_l1_mm1_SOURCES = $(srcdir)/HWF_n2_l1_mm1.c ref-HWF.c
HWF_n2_l1_mm1_CFLAGS  = $(AM_CFLAGS)
HWF_n2_l1_mm1_LDFLAGS = $(AM_LDFLAGS)

HWF_n2_l1_m0_SOURCES = $(srcdir)/HWF_n2_l1_m0.c ref-HWF.c
HWF_n2_l1_m0_CFLAGS  = $(AM_CFLAGS)
HWF_n2_l1_m0_LDFLAGS = $(AM_LDFLAGS)

HWF_n2_l1_mp1_SOURCES = $(srcdir)/HWF_n2_l1_mp1.c ref-HWF.c
HWF_n2_l1_mp1_CFLAGS  = $(AM_CFLAGS)
HWF_n2_l1_mp1_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += HWF_n2_l0_m0.sh \
		       HWF_n2_l1_mm1.sh \
		       HWF_n2_l1_m0.sh \
		       HWF_n2_l1_mp1.sh


TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(SHELL)

TESTS = $(dist_noinst_SCRIPTS)
