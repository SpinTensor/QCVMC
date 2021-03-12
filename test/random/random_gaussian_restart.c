#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <float.h>

#include <mt_random.h>

int main(int argc, char **argv) {
#define NSAMPLES 65536
   const int nsamples = NSAMPLES;
   double ref_samples[NSAMPLES];
   const int seed = 1337;
   const int ntests = 128;

   // initialize random number generator
   rng_gaussian_t rng_state = init_random_gaussian(seed, 137.0, 42.0);

   for (int itest=0; itest<128; itest++) {
      // store the rng state
      char *state_string = get_random_state_gaussian(rng_state);
      // get samples
      for (int isample=0; isample<nsamples; isample++) {
         ref_samples[isample] = next_random_gaussian(&rng_state);
      }
      // restore state
      rng_state = restore_random_state_gaussian(state_string);
      free(state_string);

      // compare restarted random numbers
      for (int isample=0; isample<nsamples; isample++) {
         double sample = next_random_gaussian(&rng_state);
         if (fabs(sample - ref_samples[isample]) > 1e-16) {
            printf("Seed %d:\n",
                   seed);
            printf("   Test %d, Sample %d: %.*le != %.*le\n",
                   itest, isample,
                   DECIMAL_DIG, sample,
                   DECIMAL_DIG, ref_samples[isample]);
            return EXIT_FAILURE;
         }
      }
   }

   return EXIT_SUCCESS;
}
