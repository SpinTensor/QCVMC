double referenceAssociatedLaguerre(int n, double alpha, double x) {
   // calculating generalized Laguerre Polynomial of grade n via clenshaw recurrence
   // only the first prefactor is 1.0 the other ones are 0.0
   // Calculates f(x) = sum_{n=0}^{nmax} c(n) * L(n,x)
   // L(n+1,x) = (2n+1+a-x)/(n+1) * L(n,x) - (n+a)/(n+1) * L(n-1,x)     
   //        n = 1, 2,... ; L(0,x) = 1, L(1,x) = -x+1, ...
   // L(n+1,x) = alpha(n,x) * L(n,x) + beta(n,x) * L(n-1,x)
   // with alpha(n,x) = (2n+1+a-x)/(n+1)
   // and  beta(n,x) = -(n+a)/(n+1)
   // Therefore
   // f(x) = sum_{n=0}^{nmax} c(n) * L(n,x)
   // can be calculated using a Clenshaw recursion
   // (c(n) are the coefficients for the Legendre polynomial expansion)
   //  
   // f(x) = beta(1,x)*L(0,x)*y(2) + L(1,x)*y(1) + L(0,x)*c(0)
   // beta(1,x) = -(1+a)/2
   // y(n) is calculated in the following way:
   // y(nmax+1) = 0
   // y(nmax+2) = 0
   // y(n) = alpha(n,x)*y(n+1) + beta(n+1,x)*y(n+2) + c(n)
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
