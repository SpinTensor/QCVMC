#include <math.h>

double spherical_harmonics_l2_m0(double x, double y, double z){
   double z_pow2 = z * z;

   double r_pow2 = x*x + y*y + z_pow2;
   double r = sqrt(r_pow2);

   double PIlmz = 0.0;
   PIlmz += 1.500000000000000000000e+00 * z_pow2;
   PIlmz -= 5.000000000000000000000e-01 * r_pow2;

   return 6.307831305050400905188e-01 * PIlmz / r_pow2;
}
