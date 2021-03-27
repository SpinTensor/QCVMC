#include <math.h>

double spherical_harmonics_l4_mp3(double x, double y, double z){
   double x_pow2 = x * x;
   double x_pow3 = x_pow2 * x;

   double y_pow2 = y * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 1.050000000000000000000e+02 * z;
   PIlmz *= 1.408590424547527704402e-02;

   double Amxy = 0.0;
   Amxy -= 3.000000000000000000000e+00 * x * y_pow2;
   Amxy += 1.000000000000000000000e+00 * x_pow3;

   return 1.196826841204297942056e+00 * PIlmz * Amxy / r_pow4;
}
