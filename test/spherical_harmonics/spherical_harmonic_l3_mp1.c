#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <float.h>

#include <spherical_harmonics_l3_mp1.h>

double reference_spherical_harmonics_l3_mp1(double x, double y, double z) {
   double r = sqrt(x*x + y*y + z*z);
   return 0.25*sqrt(21.0/(2.0*M_PI)) * x*(4.0*z*z - x*x - y*y) / pow(r, 3);
}

int main(int argc, char **argv) {

   double rmin = 0.5;
   double rmax = 1.5;
   double deltar = 0.1;
   
   double phimin = 0.0;
   double phimax = 2.0*M_PI;
   double deltaphi = 0.2*M_PI;

   double thetamin = 0.0;
   double thetamax = M_PI;
   double deltatheta = 0.1*M_PI;

   for (double r=rmin; r<=rmax; r+=deltar) {
      for (double phi=phimin; phi<=phimax; phi+=deltaphi) {
         for (double theta=thetamin; theta<=thetamax; theta+=deltatheta) {
            double x = r * sin(theta) * cos(phi);
            double y = r * sin(theta) * sin(phi);
            double z = r * cos(theta);
            double reference = reference_spherical_harmonics_l3_mp1(x, y, z);
            double testval = spherical_harmonics_l3_mp1(x, y, z);

            double discrepancy = fabs(reference - testval);
            if (discrepancy > 1.0e-16) {
               discrepancy *= 0.5*(1.0/reference + 1.0/testval);
            }
            if (discrepancy > 1.0e-12) {
               printf("x             = %.*le\n", DECIMAL_DIG, x);
               printf("y             = %.*le\n", DECIMAL_DIG, y);
               printf("z             = %.*le\n", DECIMAL_DIG, z);
               printf("refSphHarm    = %.*le\n", DECIMAL_DIG, reference);
               printf("TestedSphHarm = %.*le\n", DECIMAL_DIG, testval);
               return EXIT_FAILURE;
            }
         }
      }
   }

   return EXIT_SUCCESS;
}
