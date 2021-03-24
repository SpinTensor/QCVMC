#include <math.h>

double spherical_harmonics_l2_mp2(double x, double y, double z){
   double x_pow2 = x * x;

   double y_pow2 = y * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r = sqrt(r_pow2);

   double PIlmz = 0.0;
   PIlmz += 3.000000000000000000000e+00;
   PIlmz *= 2.041241452319315086150e-01;

   double Amxy = 0.0;
   Amxy -= 1.000000000000000000000e+00 * y_pow2;
   Amxy += 1.000000000000000000000e+00 * x_pow2;

   return 8.920620580763856111162e-01 * PIlmz * Amxy / r_pow2;
}
