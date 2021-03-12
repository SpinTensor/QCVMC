AM_CFLAGS = -I$(top_srcdir)/src/
AM_LDFLAGS = -L$(top_builddir)/src/ -lmtrandom -lm

check_PROGRAMS = random_int_init \
		 random_long_int_init \
		 random_uniform_init \
		 random_gaussian_init
		
random_int_init_SOURCES = $(srcdir)/random_int_init.c
random_int_init_CFLAGS  = $(AM_CFLAGS)
random_int_init_LDFLAGS = $(AM_LDFLAGS)

random_long_int_init_SOURCES = $(srcdir)/random_long_int_init.c
random_long_int_init_CFLAGS  = $(AM_CFLAGS)
random_long_int_init_LDFLAGS = $(AM_LDFLAGS)

random_uniform_init_SOURCES = $(srcdir)/random_long_int_init.c
random_uniform_init_CFLAGS  = $(AM_CFLAGS)
random_uniform_init_LDFLAGS = $(AM_LDFLAGS)

random_gaussian_init_SOURCES = $(srcdir)/random_long_int_init.c
random_gaussian_init_CFLAGS  = $(AM_CFLAGS)
random_gaussian_init_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS = random_int_init.sh \
		      random_long_int_init.sh \
		      random_uniform_init.sh \
		      random_gaussian_init.sh

TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(SHELL)

TESTS = $(dist_noinst_SCRIPTS)
