#include <math.h>

double spherical_harmonics_l4_mm4(double x, double y, double z){
   double x_pow2 = x * x;
   double x_pow3 = x_pow2 * x;

   double y_pow2 = y * y;
   double y_pow3 = y_pow2 * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 1.050000000000000000000e+02;
   PIlmz *= 4.980119205559973422082e-03;

   double Bmxy = 0.0;
   Bmxy -= 4.000000000000000000000e+00 * x * y_pow3;
   Bmxy += 4.000000000000000000000e+00 * x_pow3 * y;

   return 1.196826841204297942056e+00 * PIlmz * Bmxy / r_pow4;
}
