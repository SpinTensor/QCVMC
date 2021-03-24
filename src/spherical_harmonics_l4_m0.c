#include <math.h>

double spherical_harmonics_l4_m0(double x, double y, double z){
   double z_pow2 = z * z;
   double z_pow4 = z_pow2 * z_pow2;

   double r_pow2 = x*x + y*y + z_pow2;
   double r = sqrt(r_pow2);
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 4.375000000000000000000e+00 * z_pow4;
   PIlmz -= 3.750000000000000000000e+00 * r_pow2 * z_pow2;
   PIlmz += 3.750000000000000000000e-01 * r_pow4;

   return 8.462843753216344744317e-01 * PIlmz / r_pow4;
}
