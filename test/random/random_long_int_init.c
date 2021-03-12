#include <stdio.h>
#include <stdlib.h>

#include <mt_random.h>

int main(int argc, char **argv) {
   const int nsamples = 8192;
   const int nseeds = 1337;

   for (int iseed=1; iseed<nseeds; iseed++) {
      rng_int_t rng_state1 = init_rng_int(iseed);
      rng_int_t rng_state2 = init_rng_int(iseed);

      for (int isample=0; isample<nsamples; isample++) {
         long int rng1 = next_random_long_int(&rng_state1);
         long int rng2 = next_random_long_int(&rng_state2);
         if (rng1 != rng2) {
            printf("Seed %d:\n",
                   iseed);
            printf("   Sample %d: %ld != %ld\n",
                   isample, rng1, rng2);
            return EXIT_FAILURE;
         }
      }
   }

   return EXIT_SUCCESS;
}
