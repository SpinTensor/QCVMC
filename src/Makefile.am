noinst_LTLIBRARIES = libmtrandom.la \
		     liblaguerre.la \
		     libspherical_harmonics.la

bin_PROGRAMS = qcvmc

qcvmc_SOURCES = qcvmc.c
qcvmc_CPPFLAGS = 
qcvmc_CFLAGS = -g -Wall -Wextra -Wpedantic
qcvmc_LDFLAGS = -lm
qcvmc_LDADD = libmtrandom.la \
	      liblaguerre.la \
	      libspherical_harmonics.la

###########################
# Random Number Generator #
###########################
libmtrandom_la_SOURCES = mt_random.c
libmtrandom_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libmtrandom_la_LDFLAGS = -lm

######################
# Laguerre Functions #
######################
liblaguerre_la_SOURCES = laguerre.c
liblaguerre_la_CFLAGS = -g -Wall -Wextra -Wpedantic
liblaguerre_la_LDFLAGS =

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
