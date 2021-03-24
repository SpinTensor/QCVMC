#include <math.h>

double spherical_harmonics_l4_mm3(double x, double y, double z){
   double x_pow2 = x * x;

   double y_pow2 = y * y;
   double y_pow3 = y_pow2 * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r = sqrt(r_pow2);
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 1.050000000000000000000e+02 * z;
   PIlmz *= 1.408590424547527704402e-02;

   double Bmxy = 0.0;
   Bmxy -= 1.000000000000000000000e+00 * y_pow3;
   Bmxy += 3.000000000000000000000e+00 * x_pow2 * y;

   return 1.196826841204297942056e+00 * PIlmz * Bmxy / r_pow4;
}
