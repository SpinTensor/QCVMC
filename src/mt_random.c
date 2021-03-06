#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mt_random.h"

const int int_statelength = 1+2*9+312*17+1;
const int uniform_statelength = 1+2*17+1+int_statelength;
const int gauss_statelength = 1+4*17+9+1+uniform_statelength;
const int nn = MTSTATESIZE;
const int mm = 0x0000009C;

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Initializes a int random number generator
// Variables:
//    seed: The seed
// Return value:
//    rng_int: int random number state
/////////////////////////////////////////////////////////////////////////////
rng_int_t init_random_int(int seed) {
   rng_int_t rng_int;
   rng_int.seed = seed;
   rng_int.mtstate[0] = seed ;
   for (int i=1; i<nn; i++) {
      rng_int.mtstate[i] = 0x5851F42D4C957F2D * 
         (rng_int.mtstate[i-1]^(((unsigned long int)rng_int.mtstate[i-1])>>62)) + i;
   } 
   rng_int.mtidx = nn+1;
   return rng_int;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Initializes a uniform random number generator
// Variables:
//    seed: The seed
//    lower: lower bound of random numbers
//    upper: upper bound of random numbers
// Return value:
//    rng_uniform: uniform random number state
/////////////////////////////////////////////////////////////////////////////
rng_uniform_t init_random_uniform(int seed, double lower, double upper) {
   rng_uniform_t rng_uniform;

   rng_uniform.rng_int = init_random_int(seed);
   rng_uniform.lower = lower;
   rng_uniform.upper = upper;
   return rng_uniform;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Initializes a gaussian random number generator
// Variables:
//    seed: The seed
//    mean: Mean value of the gaussian
//    stddev: standard deviation of the gaussian
// Return value:
//    rng_gaussian: gaussian random number state
/////////////////////////////////////////////////////////////////////////////
rng_gaussian_t init_random_gaussian(int seed, double mean, double stddev) {
   rng_gaussian_t rng_gaussian;

   rng_gaussian.rng_uniform = init_random_uniform(seed, 0.0, 1.0);
   rng_gaussian.mean = mean;
   rng_gaussian.stddev = stddev;
   rng_gaussian.z1 = 0.0;
   rng_gaussian.z2 = 0.0;
   rng_gaussian.generated = false;
   return rng_gaussian;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Generates the next int random number
// Variables:
//    rng_int: Random number generator state
// Return value:
//    randnum: next random number
/////////////////////////////////////////////////////////////////////////////
long int next_random_long_int(rng_int_t *rng_int) {

   unsigned long int rng = 0;

   const unsigned long int um = 0xFFFFFFFF80000000;
   const unsigned long int lm = 0x000000007FFFFFFF;
   const unsigned long int mag[2] = {0x0000000000000000, 0xB5026F5AA96619E9} ;

   // if pool of random numbers is drained create a set of new ones
   if (rng_int->mtidx > nn-2) {
      for (int i=0; i<nn-mm; i++) {
         rng = (rng_int->mtstate[i] & um) ^ (rng_int->mtstate[i+1] & lm);
         rng_int->mtstate[i] = (rng_int->mtstate[i+mm] ^ (rng>>1)) ^ (mag[(rng& 1)]) ;
      }

      for (int i=nn-mm; i<nn-1; i++) {
         rng = (rng_int->mtstate[i] & um) ^ (rng_int->mtstate[i+1] & lm);
         rng_int->mtstate[i] = (rng_int->mtstate[i+mm-nn] ^ (rng>>1)) ^ (mag[(rng& 1)]) ;
      }

      rng = (rng_int->mtstate[nn-1] & um) ^ (rng_int->mtstate[0] & lm);
      rng_int->mtstate[nn-1] = (rng_int->mtstate[mm-1] ^ (rng>>1)) ^ (mag[(rng& 1)]) ;

      rng_int->mtidx = -1 ;
   }

   // get a number from stack and mix it up to produce the final random number
   rng_int->mtidx += 1 ;
   rng = rng_int->mtstate[rng_int->mtidx] ;

   rng = (rng) ^ ((rng>>29) & 0x5555555555555555) ;
   rng = (rng) ^ ((rng<<17) & 0x71d67fffeda60000) ;
   rng = (rng) ^ ((rng<<37) & 0xfff7eee000000000) ;
   rng = (rng) ^  (rng>>43) ;

   return (long int) rng;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Generates the next int random number
// Variables:
//    rng_int: Random number generator state
// Return value:
//    randnum: next random number
/////////////////////////////////////////////////////////////////////////////
int next_random_int(rng_int_t *rng_int) {
   return (int) ((unsigned long int)next_random_long_int(rng_int)>>32);
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Generates the next int random number
// Variables:
//    rng_uniform: Random number generator state
// Return value:
//    randnum: next random number
/////////////////////////////////////////////////////////////////////////////
double next_random_uniform(rng_uniform_t *rng_uniform) {
   unsigned long int irng = next_random_long_int(&rng_uniform->rng_int);
   double randnum = (1.0/((double)0x001FFFFFFFFFFFFF)) * (double)(irng>>11);
   randnum *= rng_uniform->upper - rng_uniform->lower;
   randnum += rng_uniform->lower;
   return randnum;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Generates the next int random number
// Variables:
//    rng_gaussian: Random number generator state
// Return value:
//    randnum: next random number
/////////////////////////////////////////////////////////////////////////////
double next_random_gaussian(rng_gaussian_t *rng_gaussian) {

   if (rng_gaussian->generated) {
      rng_gaussian->generated = false;
      return rng_gaussian->z2 * rng_gaussian->stddev + rng_gaussian->mean;
   }

   double u1=next_random_uniform(&rng_gaussian->rng_uniform);
   double u2=next_random_uniform(&rng_gaussian->rng_uniform);
   while (u1 <= __DBL_EPSILON__) {
      u1 = next_random_uniform(&rng_gaussian->rng_uniform);
      u2 = next_random_uniform(&rng_gaussian->rng_uniform);
   }

   double tmp1 = sqrt(-2.0*log(u1));
   double tmp2 = 2.0 * M_PI * u2;
   rng_gaussian->z1 = tmp1*cos(tmp2);
   rng_gaussian->z2 = tmp1*sin(tmp2);
   rng_gaussian->generated = true;
   
   return rng_gaussian->z1 * rng_gaussian->stddev + rng_gaussian->mean;
   
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Save rng state to a string
// Variables:
//    rng_int: Random number generator state
// Return value:
//    intstate: that contains all the state information
/////////////////////////////////////////////////////////////////////////////
char *get_random_state_int(rng_int_t rng_int) {
   char *intstate = (char*)malloc(int_statelength*sizeof(char));
   char *tmpchar = intstate;

   sprintf(tmpchar, "I %8x %8x", rng_int.seed, rng_int.mtidx);
   tmpchar += 19;
   for (int i=0; i<MTSTATESIZE; i++) {
      sprintf(tmpchar, "%17lx", rng_int.mtstate[i]);
      tmpchar += 17;
   }

   return intstate;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Save rng state to a string
// Variables:
//    rng_uniform: Random number generator state
// Return value:
//    uniformstate: that contains all the state information
/////////////////////////////////////////////////////////////////////////////
char *get_random_state_uniform(rng_uniform_t rng_uniform) {
   char *unistate = (char*)malloc(uniform_statelength*sizeof(char));
   char *tmpchar = unistate;
   void *v;
   
   v = &(rng_uniform.lower);
   sprintf(tmpchar, "U%17lx", *((unsigned long int*)v));
   tmpchar += 18;
   v = &(rng_uniform.upper);
   sprintf(tmpchar, "%17lx ", *((unsigned long int*)v));
   tmpchar += 17;
   
   char *intstate = get_random_state_int(rng_uniform.rng_int);

   tmpchar++;
   strcpy(tmpchar, intstate);
   free(intstate);
   intstate = NULL;

   return unistate;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Save rng state to a string
// Variables:
//    rng_gaussian: Random number generator state
// Return value:
//    gaussianstate: that contains all the state information
/////////////////////////////////////////////////////////////////////////////
char *get_random_state_gaussian(rng_gaussian_t rng_gaussian) {
   char *gaussstate = (char*)malloc(gauss_statelength*sizeof(char));
   char *tmpchar = gaussstate;
   void *v;

   v = &(rng_gaussian.mean);
   sprintf(tmpchar, "G%17lx", *((unsigned long int*)v));
   tmpchar += 18;
   v = &(rng_gaussian.stddev);
   sprintf(tmpchar, "%17lx", *((unsigned long int*)v));
   tmpchar += 17;
   v = &(rng_gaussian.z1);
   sprintf(tmpchar, "%17lx", *((unsigned long int*)v));
   tmpchar += 17;
   v = &(rng_gaussian.z2);
   sprintf(tmpchar, "%17lx", *((unsigned long int*)v));
   tmpchar += 17;
   v = &(rng_gaussian.generated);
   sprintf(tmpchar, "%9x ", *((unsigned int*)v));
   tmpchar += 10;
   
   char *unistate = get_random_state_uniform(rng_gaussian.rng_uniform);

   strcpy(tmpchar, unistate);
   free(unistate);
   unistate = NULL;

   return gaussstate;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Restore rng state from a string
// Variables:
//    intstate: that contains all the state information
// Return value:
//    rng_int: Random number generator state
/////////////////////////////////////////////////////////////////////////////
rng_int_t restore_random_state_int(char *intstate) {
   rng_int_t rng_int;
   char rngt;

   sscanf(intstate, "%c", &rngt);
   if (rngt != 'I') {
      fprintf(stderr, "Error in restoring int random number generator.");
      abort();
   }
   
   intstate += 2;
   sscanf(intstate, " %8x %8x", (unsigned int*) &rng_int.seed, (unsigned int*) &rng_int.mtidx);
   intstate += 18;

   for (int i = 0; i<MTSTATESIZE; i++) {
      sscanf(intstate, "%17lx", (unsigned long*) &rng_int.mtstate[i]);
      intstate += 17;
   } 

   return rng_int;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Restore rng state from a string
// Variables:
//    uniformstate: that contains all the state information
// Return value:
//    rng_uniform: Random number generator state
/////////////////////////////////////////////////////////////////////////////
rng_uniform_t restore_random_state_uniform(char *uniformstate) {
   rng_uniform_t rng_uniform;
   char rngt;
   
   sscanf(uniformstate, "%c", &rngt);
   if (rngt != 'U') {
      fprintf(stderr, "Error in restoring uniform random number generator.");
      abort();
   }

   void *v = NULL;
   uniformstate += 1;
   v = &rng_uniform.lower;
   sscanf(uniformstate, "%17lx", (unsigned long int*)v);
   uniformstate += 17;
   v = &rng_uniform.upper;
   sscanf(uniformstate, "%17lx", (unsigned long int*)v);
   uniformstate += 17;

   uniformstate++;
   rng_uniform.rng_int = restore_random_state_int(uniformstate);
   
   return rng_uniform;
}

/////////////////////////////////////////////////////////////////////////////
// Description:
//    Restore rng state from a string
// Variables:
//    gaussianstate: that contains all the state information
// Return value:
//    rng_gaussian: Random number generator state
/////////////////////////////////////////////////////////////////////////////
rng_gaussian_t restore_random_state_gaussian(char *gaussianstate) {
   rng_gaussian_t rng_gaussian;
   char rngt;

   sscanf(gaussianstate, "%c", &rngt);
   if (rngt != 'G') {
      fprintf(stderr, "Error in restoring gaussian random number generator.");
      abort();
   }

   void *v = NULL;
   gaussianstate += 1;
   v = &rng_gaussian.mean;
   sscanf(gaussianstate, "%17lx", (unsigned long int*)v);
   gaussianstate += 17;
   v = &rng_gaussian.stddev;
   sscanf(gaussianstate, "%17lx", (unsigned long int*)v);
   gaussianstate += 17;
   v = &rng_gaussian.z1;
   sscanf(gaussianstate, "%17lx", (unsigned long int*)v);
   gaussianstate += 17;
   v = &rng_gaussian.z2;
   sscanf(gaussianstate, "%17lx", (unsigned long int*)v);
   gaussianstate += 17;

   v = &rng_gaussian.generated;
   sscanf(gaussianstate, "%9lx", (unsigned long int*)v);
   gaussianstate += 9;

   gaussianstate++;
   rng_gaussian.rng_uniform = restore_random_state_uniform(gaussianstate);
   
   return rng_gaussian;
}
