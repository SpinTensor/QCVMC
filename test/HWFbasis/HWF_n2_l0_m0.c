#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <float.h>

#include <ref-HWF.h>
#include <HWF_n2_l0_m0.h>

int main(int argc, char **argv) {

   const double rmin = 0.1;
   const double rmax = 10;
   const double deltar = 0.1;

   const double phimin = 0.0;
   const double phimax = 2.0*M_PI;
   const double deltaphi = 0.2*M_PI;

   const double thetamin = 0.0;
   const double thetamax = M_PI;
   const double deltatheta = 0.1*M_PI;

   const int Z = 1;
   const int n = 2;
   const int l = 0;
   const int m = 0;

   for (double r=rmin; r<=rmax; r+=deltar) {
      for (double phi=phimin; phi<=phimax; phi+=deltaphi) {
         for (double theta=thetamin; theta<=thetamax; theta+=deltatheta) {
            double x = r * sin(theta) * cos(phi);
            double y = r * sin(theta) * sin(phi);
            double z = r * cos(theta);
            double reference = refHWF(Z, n, l, m, x, y, z);
            double testval = HWF_n2_l0_m0(Z, x, y, z);

            double discrepancy = fabs(reference - testval);
            if (discrepancy > 1.0e-16) {
               discrepancy *= 0.5*(1.0/reference + 1.0/testval);
            }
            if (discrepancy > 1.0e-12) {
               printf("x          = %.*le\n", DECIMAL_DIG, x);
               printf("y          = %.*le\n", DECIMAL_DIG, y);
               printf("z          = %.*le\n", DECIMAL_DIG, z);
               printf("refHWF     = %.*le\n", DECIMAL_DIG, reference);
               printf("TestedHWF  = %.*le\n", DECIMAL_DIG, testval);
               return EXIT_FAILURE;
            }
         }
      }
   }

   return EXIT_SUCCESS;
}
