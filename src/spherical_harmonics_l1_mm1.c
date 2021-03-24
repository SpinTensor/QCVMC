#include <math.h>

double spherical_harmonics_l1_mm1(double x, double y, double z){
   double r_pow2 = x*x + y*y + z*z;
   double r = sqrt(r_pow2);

   double PIlmz = 0.0;
   PIlmz += 1.000000000000000000000e+00;
   PIlmz *= 7.071067811865475727373e-01;

   double Bmxy = 0.0;
   Bmxy += 1.000000000000000000000e+00 * y;

   return 6.909882989426709976044e-01 * PIlmz * Bmxy / r;
}
