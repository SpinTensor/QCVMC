#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <mt_random.h>

int main(int argc, char **argv) {
   const int nskip = 65537;
#define NSAMPLES 16
   const int nsamples = NSAMPLES;
   const int seed = 1337;

   // initialize random number generator
   rng_int_t rng_state = init_random_int(seed);

   long int ref_samples[NSAMPLES] = {
      -9021340796058515322,
      -2263678289152066248,
      -3433885517309212355,
       3842397773125097574,
       5941544010031408685,
      -4380304694247862275,
      -6619076878569796473,
      -3620543911418858068,
      -6576679122555068791,
       8365756650024279427,
      -6572386091298829301,
       4627146147674095317,
      -5115288101804401604,
       1758658700833677762,
      -5067331619183563875,
      -1541142883136479469};

   for (int isample=0; isample<nsamples; isample++) {
      for (int iskip=0; iskip<nskip; iskip++) {
         next_random_long_int(&rng_state);
      }
      long int sample = next_random_long_int(&rng_state);
      if (sample != ref_samples[isample]) {
         printf("Seed %d:\n",
                seed);
         printf("   Sample %d: %ld != %ld\n",
                isample, sample, ref_samples[isample]);
         return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}
