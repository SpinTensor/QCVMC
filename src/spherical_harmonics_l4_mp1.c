#include <math.h>

double spherical_harmonics_l4_mp1(double x, double y, double z){
   double z_pow2 = z * z;
   double z_pow3 = z_pow2 * z;

   double r_pow2 = x*x + y*y + z_pow2;
   double r = sqrt(r_pow2);
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 1.750000000000000000000e+01 * z_pow3;
   PIlmz -= 7.500000000000000000000e+00 * r_pow2 * z;
   PIlmz *= 2.236067977499789638518e-01;

   double Amxy = 0.0;
   Amxy += 1.000000000000000000000e+00 * x;

   return 1.196826841204297942056e+00 * PIlmz * Amxy / r_pow4;
}
