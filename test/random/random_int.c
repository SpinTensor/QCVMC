#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <mt_random.h>

int main(int argc, char **argv) {
   const int nskip = 65537;
   const int nsamples = 16;
   const int seed = 1337;

   // initialize random number generator
   rng_integer_type rng_statei = init

   int *samples = (int*) malloc(nsamples*sizeof(int));
   for (int isample=0; isample<nsamples; isample++) {
      for (int iskip=0; iskip<nskip; iskip++) {
         next

   free(samples);

   return 0;
}
