#include <math.h>

double refAssLaguerre(int n, double alpha, double x) {
   double y0 = 0.0;
   double y1 = 1.0;
   double y2 = 0.0;
   if (n==0){return y1;}
   for (int i=n-1; i>0 ; i--){
      y0 = (2.0*i+1.0+alpha-x)/(i+1.0)*y1 - (i+1.0+alpha)/(i+2.0)*y2;
      y2 = y1; 
      y1 = y0; 
   }   
   return -0.5*(1.0+alpha)*y2 + (1.0+alpha-x)*y1;
}

long long int factorial(int n) {
   long long int fact = 1;
   for (long long int i=1; i<=n; i++) {
      fact *= i;
   }
   return fact;
}

long long int binomial_coefficient(int n, int k) {
   long long int bc = factorial(n);
   bc /= factorial(k);
   bc /= factorial(n-k);
   return bc;
}

int Amxy_prefactor(long int m, long int p) {
   long int mp = (m-p)%4;
   if (mp == 0) {return 1;}
   if (mp == 1) {return 0;}
   if (mp == 2) {return -1;}
   if (mp == 3) {return 0;}
   return 0;
}

int Bmxy_prefactor(long int m, long int p) {
   long int mp = (m-p)%4;
   if (mp == 0) {return 0;}
   if (mp == 1) {return 1;}
   if (mp == 2) {return 0;}
   if (mp == 3) {return -1;}
   return 0;
}

double refSphereHarm(int l, int m,
                     double x, double y, double z) {
   int absm = m < 0 ? -m : m;
   double r = sqrt(x*x + y*y + z*z);

   // Compute PI_l^m(z)
   double PIlmz;
   if (l != 0) {
      PIlmz = 0.0;
      for (int k=0; k<=(l-absm)/2; k++) {
         double kterm = k%2 == 0 ? 1 : -1;
         kterm /= pow(2.0, l);
         kterm *= binomial_coefficient(l, k);
         kterm *= binomial_coefficient(2*(l-k), l);
         if (m != 0) {
            kterm *= factorial(l-2*k);
            kterm /= factorial(l-2*k-absm);
         }
         kterm *= pow(r, 2*k);
         kterm *= pow(z, l-2*k-absm);
         PIlmz += kterm;
      }
      double PIprefac = factorial(l-absm);
      PIprefac /= factorial(l+absm);
      PIprefac = sqrt(PIprefac);
      PIlmz *= PIprefac;
   } else {
      PIlmz = 1.0;
   }

   // Compute A(m,x,y)-terms
   double Amxy;
   if (m > 0) {
      Amxy = 0.0;
      for (int p=0; p<=absm; p++) {
         int Amxyprefac = Amxy_prefactor(absm, p);
         if (Amxyprefac != 0) {
            double pterm = Amxyprefac;
            pterm *= binomial_coefficient(absm, p);
            pterm *= pow(x, p);
            pterm *= pow(y, absm-p);
            Amxy += pterm;
         }
      }
   } else {
      Amxy = 1.0;
   }

   // Compute B(m,x,y)-terms
   double Bmxy;
   if (m < 0) {
      Bmxy = 0.0;
      for (int p=0; p<=absm; p++) {
         int Bmxyprefac = Bmxy_prefactor(absm, p);
         if (Bmxyprefac != 0) {
            double pterm = Bmxyprefac;
            pterm *= binomial_coefficient(absm, p);
            pterm *= pow(x, p);
            pterm *= pow(y, absm-p);
            Bmxy += pterm;
         }
      }
   } else {
      Bmxy = 1.0;
   }

   // Compute Norm
   double norm;
   if (absm == 0) {
      norm = sqrt((2*l+1)/(4*M_PI));
   } else {
      norm = sqrt((2*l+1)/(2*M_PI));
   }

   // combine everything
   return norm * PIlmz * Amxy * Bmxy / pow(r, l);
}

double refHWF(int Z,
              int n, int l, int m,
              double x, double y, double z) {
   double r = sqrt(x*x + y*y + z*z);
   double rho = 2.0*Z*r/n;

   double norm = pow((2.0*Z)/n, 3);
   norm *= factorial(n-l-1) / (2.0*n*factorial(n+l));
   norm = sqrt(norm);

   double WF = norm * exp(-0.5*rho) * pow(rho, l);
   WF *= refAssLaguerre(n-l-1,2.0*l+1.0, rho);
   WF *= refSphereHarm(l, m, x, y, z);
   return WF;
}
