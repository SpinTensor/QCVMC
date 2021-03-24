#include <math.h>

double spherical_harmonics_l1_m0(double x, double y, double z){
   double r_pow2 = x*x + y*y + z*z;
   double r = sqrt(r_pow2);

   double PIlmz = 0.0;
   PIlmz += 1.000000000000000000000e+00 * z;

   return 4.886025119029199226262e-01 * PIlmz / r;
}
