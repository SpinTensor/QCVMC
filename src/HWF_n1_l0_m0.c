#include <math.h>

double HWF_n1_l0_m0(int Z, double x, double y, double z) {
   double r = sqrt(x*x + y*y + z*z);
   return sqrt(Z*Z*Z/M_PI)*exp(-Z*r);
}
