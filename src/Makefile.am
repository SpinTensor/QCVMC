noinst_LTLIBRARIES = libmtrandom.la \
		     libmp_consts.la \
		     libassociated_laguerre.la \
		     libspherical_harmonics.la

bin_PROGRAMS = qcvmc

noinst_PROGRAMS =

CLEANFILES =

qcvmc_SOURCES = qcvmc.c
qcvmc_CPPFLAGS =
qcvmc_CFLAGS = -g -Wall -Wextra -Wpedantic
qcvmc_LDFLAGS = -lm
qcvmc_LDADD = libmtrandom.la \
	      libmp_consts.la \
	      libassociated_laguerre.la \
	      libspherical_harmonics.la

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


#################################
# Associated Laguerre Functions #
#################################
libassociated_laguerre_la_SOURCES = associated_laguerre_n0.c \
			 associated_laguerre_n1.c \
			 associated_laguerre_n2.c
libassociated_laguerre_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libassociated_laguerre_la_LDFLAGS =

#######################
# Spherical Harmonics #
#######################
libspherical_harmonics_la_SOURCES = spherical_harmonics_l0_m0.c \
				    spherical_harmonics_l1_m0.c \
				    spherical_harmonics_l1_mm1.c \
				    spherical_harmonics_l1_mp1.c \
				    spherical_harmonics_l2_m0.c \
				    spherical_harmonics_l2_mm1.c \
				    spherical_harmonics_l2_mm2.c \
				    spherical_harmonics_l2_mp1.c \
				    spherical_harmonics_l2_mp2.c \
				    spherical_harmonics_l3_m0.c \
				    spherical_harmonics_l3_mm1.c \
				    spherical_harmonics_l3_mm2.c \
				    spherical_harmonics_l3_mm3.c \
				    spherical_harmonics_l3_mp1.c \
				    spherical_harmonics_l3_mp2.c \
				    spherical_harmonics_l3_mp3.c \
				    spherical_harmonics_l4_m0.c \
				    spherical_harmonics_l4_mm1.c \
				    spherical_harmonics_l4_mm2.c \
				    spherical_harmonics_l4_mm3.c \
				    spherical_harmonics_l4_mm4.c \
				    spherical_harmonics_l4_mp1.c \
				    spherical_harmonics_l4_mp2.c \
				    spherical_harmonics_l4_mp3.c \
				    spherical_harmonics_l4_mp4.c
libspherical_harmonics_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libspherical_harmonics_la_LDFLAGS =
