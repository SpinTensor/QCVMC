#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <mt_random.h>

int main(int argc, char **argv) {
#define NSAMPLES 65536
   const int nsamples = NSAMPLES;
   int ref_samples[NSAMPLES];
   const int seed = 1337;
   const int ntests = 128;

   // initialize random number generator
   rng_int_t rng_state = init_random_int(seed);

   for (int itest=0; itest<128; itest++) {
      // store the rng state
      char *state_string = get_random_state_int(rng_state);
      // get samples
      for (int isample=0; isample<nsamples; isample++) {
         ref_samples[isample] = next_random_int(&rng_state);
      }
      // restore state
      rng_state = restore_random_state_int(state_string);
      free(state_string);

      // compare restarted random numbers
      for (int isample=0; isample<nsamples; isample++) {
         int sample = next_random_int(&rng_state);
         if (sample != ref_samples[isample]) {
            printf("Seed %d:\n",
                   seed);
            printf("   Test %d, Sample %d: %d != %d\n",
                   itest, isample,
                   sample, ref_samples[isample]);
            return EXIT_FAILURE;
         }
      }
   }

   return EXIT_SUCCESS;
}
