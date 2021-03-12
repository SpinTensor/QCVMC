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

   int ref_samples[NSAMPLES] = {
      -2100444585,
       -527053674,
       -799513776,
        894627946,
       1383373516,
      -1019869162,
      -1541123931,
       -842973570,
      -1531252434,
       1947804505,
      -1530252884,
       1077341415,
      -1190995822,
        409469637,
      -1179830083,
       -358825290};

   for (int isample=0; isample<nsamples; isample++) {
      for (int iskip=0; iskip<nskip; iskip++) {
         next_random_int(&rng_state);
      }
      int sample = next_random_int(&rng_state);
      if (sample != ref_samples[isample]) {
         printf("Seed %d:\n",
                seed);
         printf("   Sample %d: %d != %d\n",
                isample, sample, ref_samples[isample]);
         return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}
