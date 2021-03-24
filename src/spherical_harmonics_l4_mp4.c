#include <math.h>

double spherical_harmonics_l4_mp4(double x, double y, double z){
   double x_pow2 = x * x;
   double x_pow4 = x_pow2 * x_pow2;

   double y_pow2 = y * y;
   double y_pow4 = y_pow2 * y_pow2;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r = sqrt(r_pow2);
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 1.050000000000000000000e+02;
   PIlmz *= 4.980119205559973422082e-03;

   double Amxy = 0.0;
   Amxy += 1.000000000000000000000e+00 * y_pow4;
   Amxy -= 6.000000000000000000000e+00 * x_pow2 * y_pow2;
   Amxy += 1.000000000000000000000e+00 * x_pow4;

   return 1.196826841204297942056e+00 * PIlmz * Amxy / r_pow4;
}
