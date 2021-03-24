AM_CFLAGS = -I$(top_srcdir)/src/
AM_LDFLAGS = -L$(top_builddir)/src/ -llaguerre -lm
check_PROGRAMS = 
dist_noinst_SCRIPTS =

check_PROGRAMS += laguerre
		
laguerre_SOURCES = $(srcdir)/laguerre.c
laguerre_CFLAGS  = $(AM_CFLAGS)
laguerre_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += laguerre.sh

TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(SHELL)

TESTS = $(dist_noinst_SCRIPTS)
