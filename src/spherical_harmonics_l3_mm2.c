#include <math.h>

double spherical_harmonics_l3_mm2(double x, double y, double z){
   double x_pow2 = x * x;

   double y_pow2 = y * y;

   double r_pow2 = x_pow2 + y_pow2 + z*z;
   double r = sqrt(r_pow2);
   double r_pow3 = r_pow2 * r;

   double PIlmz = 0.0;
   PIlmz += 1.500000000000000000000e+01 * z;
   PIlmz *= 9.128709291752767907013e-02;

   double Bmxy = 0.0;
   Bmxy += 2.000000000000000000000e+00 * x * y;

   return 1.055502061411188075013e+00 * PIlmz * Bmxy / r_pow3;
}
