#include <math.h>

double spherical_harmonics_l3_mp3(double x, double y, double z){
   double x_pow2 = x * x;
   double x_pow3 = x_pow2 * x;

   double y_pow2 = y * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r = sqrt(r_pow2);
   double r_pow3 = r_pow2 * r;

   double PIlmz = 0.0;
   PIlmz += 1.500000000000000000000e+01;
   PIlmz *= 3.726779962499648934937e-02;

   double Amxy = 0.0;
   Amxy -= 3.000000000000000000000e+00 * x * y_pow2;
   Amxy += 1.000000000000000000000e+00 * x_pow3;

   return 1.055502061411188075013e+00 * PIlmz * Amxy / r_pow3;
}
