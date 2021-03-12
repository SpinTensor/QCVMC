#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <float.h>

#include <mt_random.h>

int main(int argc, char **argv) {
   const int nskip = 65537;
#define NSAMPLES 16
   const int nsamples = NSAMPLES;
   const int seed = 1337;

   // initialize random number generator
   rng_gaussian_t rng_state = init_random_gaussian(seed, 137.0, 42.0);

   double ref_samples[NSAMPLES] = {
      1.365757930218428839453e+02,
      4.542747667025561497667e+01,
      9.842710168094404821204e+01,
      1.587410522090522704275e+02,
      1.898781345754275662330e+02,
      1.018522852660560999993e+02,
      8.783800824660934836174e+01,
      9.295377478727624520616e+01,
      9.810854142135687538939e+01,
      1.585619426443776660562e+02,
      1.266709057925349668494e+02,
      1.912317435700961141265e+02,
      1.077804607474276537005e+02,
      1.675890532554307128521e+02,
      7.049082132977189019130e+01,
      1.093971178311926593096e+02};

   for (int isample=0; isample<nsamples; isample++) {
      for (int iskip=0; iskip<nskip; iskip++) {
         next_random_gaussian(&rng_state);
      }
      double sample = next_random_gaussian(&rng_state);
      if (fabs(sample - ref_samples[isample]) > 1e-16) {
         printf("Seed %d:\n",
                seed);
         printf("   Sample %d: %.*le != %.*le\n",
                isample,
                DECIMAL_DIG, sample,
                DECIMAL_DIG, ref_samples[isample]);
         return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}
