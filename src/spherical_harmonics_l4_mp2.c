#include <math.h>

double spherical_harmonics_l4_mp2(double x, double y, double z){
   double x_pow2 = x * x;

   double y_pow2 = y * y;

   double z_pow2 = z * z;

   double r_pow2 = x_pow2 + y_pow2 + z_pow2;
   double r = sqrt(r_pow2);
   double r_pow4 = r_pow2 * r_pow2;

   double PIlmz = 0.0;
   PIlmz += 5.250000000000000000000e+01 * z_pow2;
   PIlmz -= 7.500000000000000000000e+00 * r_pow2;
   PIlmz *= 5.270462766947298788311e-02;

   double Amxy = 0.0;
   Amxy -= 1.000000000000000000000e+00 * y_pow2;
   Amxy += 1.000000000000000000000e+00 * x_pow2;

   return 1.196826841204297942056e+00 * PIlmz * Amxy / r_pow4;
}
