#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <float.h>

#include <associated_laguerre_n0.h>

#include "reference_associated_laguerre.h"

int main(int argc, char **argv) {

   const double minalpha = -10.0;
   const double maxalpha =  10.0;
   const double deltaalpha = 0.1;

   const double minx = -10.0;
   const double maxx =  10.0;
   const double deltax = 0.1;

   for (double alpha=minalpha; alpha<=maxalpha; alpha+=deltaalpha) {
      for (double x=minx; x<=maxx; x+=deltax) {
          double reference = referenceAssociatedLaguerre(0, alpha, x);
          double testval = AssociatedLaguerre_n0(alpha, x);

          double discrepancy = fabs(reference - testval);
          if (discrepancy > 1.0e-16) {
             discrepancy *= 0.5*(1.0/reference + 1.0/testval);
          }
          if (discrepancy > 1.0e-12) {
             printf("alpha          = %.*le\n", DECIMAL_DIG, alpha);
             printf("x              = %.*le\n", DECIMAL_DIG, x);
             printf("refLaguerre    = %.*le\n", DECIMAL_DIG, reference);
             printf("TestedLaguerre = %.*le\n", DECIMAL_DIG, testval);
             return EXIT_FAILURE;
          }
      }
   }

   return EXIT_SUCCESS;
}
