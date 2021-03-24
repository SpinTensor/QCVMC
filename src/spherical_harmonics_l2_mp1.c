#include <math.h>

double spherical_harmonics_l2_mp1(double x, double y, double z){
   double r_pow2 = x*x + y*y + z*z;
   double r = sqrt(r_pow2);

   double PIlmz = 0.0;
   PIlmz += 3.000000000000000000000e+00 * z;
   PIlmz *= 4.082482904638630172300e-01;

   double Amxy = 0.0;
   Amxy += 1.000000000000000000000e+00 * x;

   return 8.920620580763856111162e-01 * PIlmz * Amxy / r_pow2;
}
