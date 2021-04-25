noinst_LTLIBRARIES = libmtrandom.la \
		     libmp_consts.la \
		     libHWFbasis.la

bin_PROGRAMS = qcvmc

noinst_PROGRAMS =

CLEANFILES =

qcvmc_SOURCES = qcvmc.c
qcvmc_CPPFLAGS =
qcvmc_CFLAGS = -g -Wall -Wextra -Wpedantic
qcvmc_LDFLAGS = -lm
qcvmc_LDADD = libmtrandom.la \
	      libmp_consts.la \
	      libHWFbasis.la

###########################
# Random Number Generator #
###########################
libmtrandom_la_SOURCES = mt_random.c
libmtrandom_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libmtrandom_la_LDFLAGS = -lm

#####################################
# Physical & Mathematical constants #
#####################################
noinst_PROGRAMS += generate_mp_consts

generate_mp_consts_SOURCES = generate_mp_consts.c
generate_mp_consts_CFLAGS = -g -Wall -Wextra -Wpedantic
generate_mp_consts_LDFLAGS = -lm

libmp_consts_la_SOURCES = mp_consts.c
libmp_consts_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libmp_consts_la_LDFLAGS =
CLEANFILES += mp_consts.c

mp_consts.c: $(srcdir)/generate_mp_consts
	./$< > $@


################################
# Hydrogen Eigenfunction Basis #
################################
libHWFbasis_la_SOURCES = HWF_n1_l0_m0.c \
			 HWF_n2_l0_m0.c \
			 HWF_n2_l1_mm1.c \
			 HWF_n2_l1_m0.c \
			 HWF_n2_l1_mp1.c
libHWFbasis_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libHWFbasis_la_LDFLAGS =
