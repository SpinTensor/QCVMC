#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <float.h>

#include <mt_random.h>

int main(int argc, char **argv) {
   const int nsamples = 8192;
   const int nseeds = 1337;
#define NMEANS 5
   int means[NMEANS] = {-137.0 -3.14, 0, 17.0, 42.42};
#define NSTDDEVS 3
   int stddevs[NSTDDEVS] = {0.1, 3.14, 1337.7331};

   for (int iseed=1; iseed<nseeds; iseed++) {
      rng_gaussian_t rng_state1 = init_rng_gaussian(iseed, means[iseed%NMEANS], stddevs[iseed%NSTDDEVS]);
      rng_gaussian_t rng_state2 = init_rng_gaussian(iseed, means[iseed%NMEANS], stddevs[iseed%NSTDDEVS]);

      for (int isample=0; isample<nsamples; isample++) {
         double rng1 = next_random_gaussian(&rng_state1);
         double rng2 = next_random_gaussian(&rng_state2);
         if (fabs(rng1 - rng2) > 1.0e-16) {
            printf("Seed %d:\n",
                   iseed);
            printf("   Sample %d: %.*le != %.*le\n",
                   isample,
                   DECIMAL_DIG, rng1,
                   DECIMAL_DIG, rng2);
            return EXIT_FAILURE;
         }
      }
   }

   return EXIT_SUCCESS;
}
