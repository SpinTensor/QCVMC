AM_CFLAGS = -I$(top_srcdir)/src/
AM_LDFLAGS = -L$(top_builddir)/src/ -lmtrandom -lm
check_PROGRAMS = 
dist_noinst_SCRIPTS =

############
# RNG Init #
############
check_PROGRAMS += random_int_init \
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

dist_noinst_SCRIPTS += random_int_init.sh \
		       random_long_int_init.sh \
		       random_uniform_init.sh \
		       random_gaussian_init.sh

###############
# RNG Numbers #
###############
check_PROGRAMS += random_int \
		  random_long_int \
		  random_uniform \
		  random_gaussian

check_PROGRAMS += random_int \
		  random_long_int \
		  random_uniform \
		  random_gaussian

random_int_SOURCES = $(srcdir)/random_int.c
random_int_CFLAGS  = $(AM_CFLAGS)
random_int_LDFLAGS = $(AM_LDFLAGS)

random_long_int_SOURCES = $(srcdir)/random_long_int.c
random_long_int_CFLAGS  = $(AM_CFLAGS)
random_long_int_LDFLAGS = $(AM_LDFLAGS)

random_uniform_SOURCES = $(srcdir)/random_uniform.c
random_uniform_CFLAGS  = $(AM_CFLAGS)
random_uniform_LDFLAGS = $(AM_LDFLAGS)

random_gaussian_SOURCES = $(srcdir)/random_gaussian.c
random_gaussian_CFLAGS  = $(AM_CFLAGS)
random_gaussian_LDFLAGS = $(AM_LDFLAGS)

dist_noinst_SCRIPTS += random_int.sh \
		       random_long_int.sh \
		       random_uniform.sh \
		       random_gaussian.sh

TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(SHELL)

TESTS = $(dist_noinst_SCRIPTS)
