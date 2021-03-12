noinst_LTLIBRARIES = libmtrandom.la

bin_PROGRAMS = qcvmc

qcvmc_SOURCES = qcvmc.c
qcvmc_CPPFLAGS = 
qcvmc_CFLAGS = -g -Wall -Wextra -Wpedantic
qcvmc_LDFLAGS = -lm
qcvmc_LDADD = libmtrandom.la

libmtrandom_la_SOURCES = mt_random.c
libmtrandom_la_CFLAGS = -g -Wall -Wextra -Wpedantic
libmtrandom_la_LDFLAGS = -lm
