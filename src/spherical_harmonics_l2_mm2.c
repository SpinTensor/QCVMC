#include <math.h>

double spherical_harmonics_l2_mm2(double x, double y, double z){
   double x_pow2 = x * x;

   double y_pow2 = y * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;

   double PIlmz = 0.0;
   PIlmz += 3.000000000000000000000e+00;
   PIlmz *= 2.041241452319315086150e-01;

   double Bmxy = 0.0;
   Bmxy += 2.000000000000000000000e+00 * x * y;

   return 8.920620580763856111162e-01 * PIlmz * Bmxy / r_pow2;
}
