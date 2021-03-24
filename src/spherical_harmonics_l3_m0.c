#include <math.h>

double spherical_harmonics_l3_m0(double x, double y, double z){
   double z_pow2 = z * z;
   double z_pow3 = z_pow2 * z;

   double r_pow2 = x*x + y*y + z_pow2;
   double r = sqrt(r_pow2);
   double r_pow3 = r_pow2 * r;

   double PIlmz = 0.0;
   PIlmz += 2.500000000000000000000e+00 * z_pow3;
   PIlmz -= 1.500000000000000000000e+00 * r_pow2 * z;

   return 7.463526651802308009565e-01 * PIlmz / r_pow3;
}
