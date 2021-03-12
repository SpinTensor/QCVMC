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
   rng_uniform_t rng_state = init_rng_uniform(seed, 42.0, 137.0);

   double ref_samples[NSAMPLES] = {
      9.054045287336093394970e+01,
      1.253421466351920514626e+02,
      1.193156258448175179865e+02,
      6.178819606258456076375e+01,
      7.259871588707287060060e+01,
      1.144416046381530804865e+02,
      1.029120167249287760569e+02,
      1.183543425218874318716e+02,
      1.031303634860322375744e+02,
      8.508331478859655305769e+01,
      1.031524724266514141391e+02,
      6.582961905215188380680e+01,
      1.106564692538884742135e+02,
      5.105702252449594169548e+01,
      1.109034432364392870340e+02,
      1.290631753054660748603e+02};

   for (int isample=0; isample<nsamples; isample++) {
      for (int iskip=0; iskip<nskip; iskip++) {
         next_random_uniform(&rng_state);
      }
      double sample = next_random_uniform(&rng_state);
      //printf("%.*le\n", DECIMAL_DIG, sample);
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
