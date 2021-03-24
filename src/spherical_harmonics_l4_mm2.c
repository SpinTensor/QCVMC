#include <math.h>

double spherical_harmonics_l4_mm2(double x, double y, double z){
   double x_pow2 = x * x;
   double x_pow3 = x_pow2 * x;

   double y_pow2 = y * y;
   double y_pow3 = y_pow2 * y;

   double z_pow2 = z * z;

   double r_pow2 = x_pow2 + y_pow2 + z_pow2;
   double r = sqrt(r_pow2);
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 5.250000000000000000000e+01 * z_pow2;
   PIlmz -= 7.500000000000000000000e+00 * r_pow2;
   PIlmz *= 5.270462766947298788311e-02;

   double Bmxy = 0.0;
   Bmxy += 2.000000000000000000000e+00 * x * y;

   return 1.196826841204297942056e+00 * PIlmz * Bmxy / r_pow4;
}
