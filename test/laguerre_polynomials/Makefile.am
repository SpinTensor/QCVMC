AM_CFLAGS = -I$(top_srcdir)/src/
AM_LDFLAGS = -L$(top_builddir)/src/ -lassociated_laguerre -lm
check_PROGRAMS = 
dist_noinst_SCRIPTS =

check_PROGRAMS += associated_laguerre_n0 \
		  associated_laguerre_n1 \
		  associated_laguerre_n2
		
associated_laguerre_n0_SOURCES = $(srcdir)/associated_laguerre_n0.c \
				 $(srcdir)/reference_associated_laguerre.c
associated_laguerre_n0_CFLAGS  = $(AM_CFLAGS)
associated_laguerre_n0_LDFLAGS = $(AM_LDFLAGS)

associated_laguerre_n1_SOURCES = $(srcdir)/associated_laguerre_n1.c \
				 $(srcdir)/reference_associated_laguerre.c
associated_laguerre_n1_CFLAGS  = $(AM_CFLAGS)
associated_laguerre_n1_LDFLAGS = $(AM_LDFLAGS)

associated_laguerre_n2_SOURCES = $(srcdir)/associated_laguerre_n2.c \
				 $(srcdir)/reference_associated_laguerre.c
associated_laguerre_n2_CFLAGS  = $(AM_CFLAGS)
associated_laguerre_n2_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += associated_laguerre_n0.sh \
		       associated_laguerre_n1.sh \
		       associated_laguerre_n2.sh

TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(SHELL)

TESTS = $(dist_noinst_SCRIPTS)
