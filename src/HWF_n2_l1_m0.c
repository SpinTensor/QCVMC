#include <math.h>

double HWF_n2_l1_m0(int Z, double x, double y, double z) {
   double r = sqrt(x*x + y*y + z*z);
   double Zr = Z*r;

   return sqrt(Z*Z*Z/(32*M_PI))*exp(-0.5*Zr)*Zr*z/r;
}
