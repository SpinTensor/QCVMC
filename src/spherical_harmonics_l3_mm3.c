#include <math.h>

double spherical_harmonics_l3_mm3(double x, double y, double z){
   double x_pow2 = x * x;

   double y_pow2 = y * y;
   double y_pow3 = y_pow2 * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r = sqrt(r_pow2);
   double r_pow3 = r_pow2 * r;

   double PIlmz = 0.0;
   PIlmz += 1.500000000000000000000e+01;
   PIlmz *= 3.726779962499648934937e-02;

   double Bmxy = 0.0;
   Bmxy -= 1.000000000000000000000e+00 * y_pow3;
   Bmxy += 3.000000000000000000000e+00 * x_pow2 * y;

   return 1.055502061411188075013e+00 * PIlmz * Bmxy / r_pow3;
}
