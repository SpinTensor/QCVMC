#include <math.h>

double spherical_harmonics_l3_mp1(double x, double y, double z){
   double z_pow2 = z * z;

   double r_pow2 = x*x + y*y + z_pow2;
   double r = sqrt(r_pow2);
   double r_pow3 = r_pow2 * r;

   double PIlmz = 0.0;
   PIlmz += 7.500000000000000000000e+00 * z_pow2;
   PIlmz -= 1.500000000000000000000e+00 * r_pow2;
   PIlmz *= 2.886751345948128655294e-01;

   double Amxy = 0.0;
   Amxy += 1.000000000000000000000e+00 * x;

   return 1.055502061411188075013e+00 * PIlmz * Amxy / r_pow3;
}
