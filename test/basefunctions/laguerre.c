#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <float.h>

#include <laguerre.h>

double referenceAssociatedLaguerre(int n, double alpha, double x) {
   if (n == 0) {
      return 1;
   } else if (n == 1) {
      return 1 + alpha - x;
   } else {
      double rn = (double) n;
      double f1 = 2.0*rn - 1.0 + alpha - x;
      double f2 = rn - 1.0 + alpha;
      double Ln = 0.0;
      Ln += f1*referenceAssociatedLaguerre(n-1, alpha, x);
      Ln -= f2*referenceAssociatedLaguerre(n-2, alpha, x);
      Ln /= rn;
      return Ln;
   }
}

int main(int argc, char **argv) {

#define NNS 11
   const int nns = NNS;
   int ns[NNS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
#define NALPHAS 5
   const int nalphas = NALPHAS;
   double alphas[NALPHAS] = {0.0, 3.14, -2.718, 7.0, -13};

#define NXS 8
   const int nxs = NXS;
   double xs[NXS] = {0.0, 1.0, 0.1, 7.23, 3.14, 2.7, 0.001, 10.0};

   for (int in=0; in<nns; in++) {
      int n = ns[in];
      for (int ialpha=0; ialpha<nalphas; ialpha++) { 
         double alpha = alphas[ialpha];
         for (int ix=0; ix<nxs; ix++) {
            for (int isign=-1; isign<2; isign+=2) {
               double x = isign*xs[ix];

               double reference = referenceAssociatedLaguerre(n, alpha, x);
               double testval = AssociatedLaguerre(n, alpha, x);

               double discrepancy = fabs(reference - testval);
               if (discrepancy > 1.0e-16) {
                  discrepancy *= 0.5*(1.0/reference + 1.0/testval);
               }
               if (discrepancy > 1.0e-12) {
                  printf("n              = %d\n", n);
                  printf("alpha          = %.*le\n", DECIMAL_DIG, alpha);
                  printf("x              = %.*le\n", DECIMAL_DIG, x);
                  printf("refLaguerre    = %.*le\n", DECIMAL_DIG, reference);
                  printf("TestedLaguerre = %.*le\n", DECIMAL_DIG, testval);
                  return EXIT_FAILURE;
               }
            }
         }
      }
   }

   return EXIT_SUCCESS;
}
