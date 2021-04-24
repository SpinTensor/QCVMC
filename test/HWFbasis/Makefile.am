AM_CFLAGS = -I$(top_srcdir)/src/ -I$(srcdir)/
AM_LDFLAGS = -L$(top_builddir)/src/ -lHWFbasis -lm
check_PROGRAMS = 
dist_noinst_SCRIPTS =


#########
# n = 1 #
#########
check_PROGRAMS += HWF_n1_l0_m0
		
HWF_n1_l0_m0_SOURCES = $(srcdir)/HWF_n1_l0_m0.c \
		       ref-HWF.c
HWF_n1_l0_m0_CFLAGS  = $(AM_CFLAGS)
HWF_n1_l0_m0_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += HWF_n1_l0_m0.sh

TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(SHELL)

TESTS = $(dist_noinst_SCRIPTS)
