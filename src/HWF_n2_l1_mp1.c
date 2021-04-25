#include <math.h>

double HWF_n2_l1_mp1(int Z, double x, double y, double z) {
   double r = sqrt(x*x + y*y + z*z);
   double Zr = Z*r;

   return sqrt(Z*Z*Z/(32.0*M_PI))*exp(-0.5*Zr)*Zr*x/r;
}
