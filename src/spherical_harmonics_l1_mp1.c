#include <math.h>

double spherical_harmonics_l1_mp1(double x, double y, double z){
   double r_pow2 = x*x + y*y + z*z;
   double r = sqrt(r_pow2);

   double PIlmz = 0.0;
   PIlmz += 1.000000000000000000000e+00;
   PIlmz *= 7.071067811865475727373e-01;

   double Amxy = 0.0;
   Amxy += 1.000000000000000000000e+00 * x;

   return 6.909882989426709976044e-01 * PIlmz * Amxy / r;
}
