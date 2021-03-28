#include <stdio.h>

#include <math.h>
#include <float.h>

int main(){
   printf("// This File is machine generated\n");
   printf("// Defines a variaty of mathematical and physical constants, as well as conversion factors\n\n");
   printf("//Mathematical constants\n");
   long double halfpi = asinl(1.0L);
   printf("const double halfpi = %.*Le;\n", DECIMAL_DIG, halfpi);
   long double ihalfpi = 1.0L/halfpi;
   printf("const double ihalfpi = %.*Le;\n", DECIMAL_DIG, ihalfpi);
   long double sqrt_halfpi = sqrtl(halfpi);
   printf("const double sqrt_halfpi = %.*Le;\n", DECIMAL_DIG, sqrt_halfpi);
   long double sqrt_ihalfpi = sqrtl(ihalfpi);
   printf("const double sqrt_ihalfpi = %.*Le;\n", DECIMAL_DIG, sqrt_ihalfpi);

   long double pi = 2.0L*halfpi;
   printf("const double pi = %.*Le;\n", DECIMAL_DIG, pi);
   long double ipi = 1.0L/pi;
   printf("const double ipi = %.*Le;\n", DECIMAL_DIG, ipi);
   long double sqrt_pi = sqrtl(pi);
   printf("const double sqrt_pi = %.*Le;\n", DECIMAL_DIG, sqrt_pi);
   long double sqrt_ipi = sqrtl(ipi);
   printf("const double sqrt_ipi = %.*Le;\n", DECIMAL_DIG, sqrt_ipi);

   long double twopi = 2.0L*pi;
   printf("const double twopi = %.*Le;\n", DECIMAL_DIG, twopi);\
   long double itwopi = 1.0L/twopi;
   printf("const double itwopi = %.*Le;\n", DECIMAL_DIG, itwopi);\
   long double sqrt_twopi = sqrtl(twopi);
   printf("const double sqrt_twopi = %.*Le;\n", DECIMAL_DIG, sqrt_twopi);
   long double sqrt_itwopi = sqrtl(itwopi);
   printf("const double sqrt_itwopi = %.*Le;\n", DECIMAL_DIG, sqrt_itwopi);

   long double e = exp(1.0L);
   printf("const double e = %.*Le;\n", DECIMAL_DIG, e);
   long double ie = 1.0L/e;
   printf("const double ie = %.*Le;\n", DECIMAL_DIG, ie);

   long double sqrt_2 = sqrtl(2.0L);
   printf("const double sqrt_2 = %.*Le;\n", DECIMAL_DIG, sqrt_2);
   long double sqrt_3 = sqrtl(3.0L);
   printf("const double sqrt_3 = %.*Le;\n", DECIMAL_DIG, sqrt_3);
   long double sqrt_1_2 = 1.0L/sqrt_2;
   printf("const double sqrt_1_2 = %.*Le;\n", DECIMAL_DIG, sqrt_1_2);
   long double sqrt_1_3 = 1.0L/sqrt_3;
   printf("const double sqrt_1_3 = %.*Le;\n", DECIMAL_DIG, sqrt_1_3);
   long double sqrt_2_3 = sqrt_2/sqrt_3;
   printf("const double sqrt_2_3 = %.*Le;\n", DECIMAL_DIG, sqrt_2_3);
   long double sqrt_3_2 = sqrt_3/sqrt_2;
   printf("const double sqrt_3_2 = %.*Le;\n", DECIMAL_DIG, sqrt_3_2);

   printf("\n");
   printf("//Physical constants\n");
   printf("// Speed of light in vacuum [m/s]\n");
   long double lightspeed = 299792458.0L;
   printf("const double lightspeed = %.*Le;\n", DECIMAL_DIG, lightspeed);

   printf("\n");
   printf("// Magnetic constant or permeability of vacuum [N/A^2]\n");
   long double mu_perm = 4.0L*pi*1.0e-7L;
   printf("const double mu_perm = %.*Le;\n", DECIMAL_DIG, mu_perm);

   printf("\n");
   printf("// Electric constant or permittivity of vacuum [F/m]\n");
   long double permittivity = 1.0L/(mu_perm*pow(lightspeed,2));
   printf("const double permittivity = %.*Le;\n", DECIMAL_DIG, permittivity);

   printf("\n");
   printf("// Planck constant [J*s]\n");
   long double h_planck = 6.62607015e-34L;
   printf("const double h_planck = %.*Le;\n", DECIMAL_DIG, h_planck);
   long double h_bar = h_planck/(2.0*pi);
   printf("const double h_bar = %.*Le;\n", DECIMAL_DIG, h_bar);

   printf("\n");
   printf("// Elementary charge [C]\n");
   long double electron_charge = 1.602176634e-19L;
   printf("const double electron_charge = %.*Le;\n", DECIMAL_DIG, electron_charge);

   printf("\n");
   printf("// Electron mass [kg]\n");
   long double electron_mass = 9.10938291e-31L;
   printf("const double electron_mass = %.*Le;\n", DECIMAL_DIG, electron_mass);

   printf("\n");
   printf("// Proton mass [kg]\n");
   long double proton_mass = 1.672621777e-27L;
   printf("const double proton_mass = %.*Le;\n", DECIMAL_DIG, proton_mass);

   printf("\n");
   printf("// Electron g factor [ ]\n");
   long double electron_gfactor = -2.00231930436153L;
   printf("const double electron_gfactor = %.*Le;\n", DECIMAL_DIG, electron_gfactor);
   
   printf("\n");
   printf("// Fine-structure constant\n");
   printf("// finestructure = 0.5*mu_perm*lightspeed*electroncharge^2/h_planck\n");
   long double finestructure = 7.2973525698e-3L;
   printf("const double finestructure = %.*Le;\n", DECIMAL_DIG, finestructure);
   
   printf("\n");
   printf("// Rydberg constant [1/m]\n");
   printf("// rydberg = 0.5*electronmass*lightspeed*finestructure^2/h_planck\n");
   long double rydberg = 10973731.568539L;
   printf("const double rydberg = %.*Le;\n", DECIMAL_DIG, rydberg);
   
   printf("\n");
   printf("// Avogadro constant [1/mol]\n");
   long double n_avogadro = 6.02214129e+23L;
   printf("const double n_avogadro = %.*Le;\n", DECIMAL_DIG, n_avogadro);

   printf("\n");
   printf("// Boltzmann constant [J/K]\n");
   long double boltzmann = 1.3806488e-23L;
   printf("const double boltzmann = %.*Le;\n", DECIMAL_DIG, boltzmann);

   printf("\n");
   printf("//Conversion factors\n");
   printf("// Length conversion\n");
   long double AU2SI_length = h_bar/(electron_mass*lightspeed*finestructure);
   printf("const double AU2SI_length = %.*Le;\n", DECIMAL_DIG, AU2SI_length);
   long double SI2AU_length = 1.0L/AU2SI_length;
   printf("const double SI2AU_length = %.*Le;\n", DECIMAL_DIG, SI2AU_length);
   long double AU2angstrom_length = AU2SI_length*10.0e10L;
   printf("const double AU2angstrom_length = %.*Le;\n", DECIMAL_DIG, AU2angstrom_length);
   long double angstrom2AU_length = 1.0L/AU2angstrom_length;
   printf("const double angstrom2AU_length = %.*Le;\n", DECIMAL_DIG, angstrom2AU_length);
   printf("// Energy conversion\n");
   long double AU2SI_energy = pow(finestructure,2)*electron_mass*pow(lightspeed,2);
   printf("const double AU2SI_energy = %.*Le;\n", DECIMAL_DIG, AU2SI_energy);
   long double SI2AU_energy = 1.0L/AU2SI_energy;
   printf("const double SI2AU_energy = %.*Le;\n", DECIMAL_DIG, SI2AU_energy);
   printf("// Time conversion \n");
   long double AU2SI_time = h_bar/AU2SI_energy;
   printf("const double AU2SI_time = %.*Le;\n", DECIMAL_DIG, AU2SI_time);
   long double SI2AU_time = 1.0L/AU2SI_time;
   printf("const double SI2AU_time = %.*Le;\n", DECIMAL_DIG, SI2AU_time);
   printf("// Velocity conversion\n");
   long double AU2SI_velocity = AU2SI_length*AU2SI_energy/h_bar;
   printf("const double AU2SI_velocity = %.*Le;\n", DECIMAL_DIG, AU2SI_velocity);
   long double SI2AU_velocity = 1.0L/AU2SI_velocity;
   printf("const double SI2AU_velocity = %.*Le;\n", DECIMAL_DIG, SI2AU_velocity);
   printf("// Mass conversion\n");
   long double AU2SI_mass = electron_mass;
   printf("const double AU2SI_mass = %.*Le;\n", DECIMAL_DIG, AU2SI_mass);
   long double SI2AU_mass = 1.0L/AU2SI_mass;
   printf("const double SI2AU_mass = %.*Le;\n", DECIMAL_DIG, SI2AU_mass);
   long double AU2U_mass = 1.0L/1822.88839L;
   printf("const double AU2U_mass = %.*Le;\n", DECIMAL_DIG, AU2U_mass);
   long double U2AU_mass = 1.0L/AU2U_mass;
   printf("const double U2AU_mass = %.*Le;\n", DECIMAL_DIG, U2AU_mass);
   printf("// Force conversion\n");
   long double AU2SI_force = AU2SI_energy/AU2SI_length;
   printf("const double AU2SI_force = %.*Le;\n", DECIMAL_DIG, AU2SI_force);
   long double SI2AU_force = 1.0L/AU2SI_force;
   printf("const double SI2AU_force = %.*Le;\n", DECIMAL_DIG, SI2AU_force);
   printf("// Temperature conversion\n");
   long double AU2SI_temperature = AU2SI_energy/boltzmann;
   printf("const double AU2SI_temperature = %.*Le;\n", DECIMAL_DIG, AU2SI_temperature);
   long double SI2AU_temperature = 1.0L/AU2SI_temperature;
   printf("const double SI2AU_temperature = %.*Le;\n", DECIMAL_DIG, SI2AU_temperature);
   printf("// Pressure conversion\n");
   long double AU2SI_pressure = AU2SI_energy/pow((AU2SI_length),3);
   printf("const double AU2SI_pressure = %.*Le;\n", DECIMAL_DIG, AU2SI_pressure);
   long double SI2AU_pressure = 1.0L/AU2SI_pressure;
   printf("const double SI2AU_pressure = %.*Le;\n", DECIMAL_DIG, SI2AU_pressure);
   printf("// Electric field conversion\n");
   long double AU2SI_efield = AU2SI_energy/(electron_charge*AU2SI_length);
   printf("const double AU2SI_efield = %.*Le;\n", DECIMAL_DIG, AU2SI_efield);
   long double SI2AU_efield = 1.0L/AU2SI_efield;
   printf("const double SI2AU_efield = %.*Le;\n", DECIMAL_DIG, SI2AU_efield);
   printf("// Electric potential conversion\n");
   long double AU2SI_epotential = AU2SI_energy/electron_charge;
   printf("const double AU2SI_epotential = %.*Le;\n", DECIMAL_DIG, AU2SI_epotential);
   long double SI2AU_epotential = 1.0L/AU2SI_epotential;
   printf("const double SI2AU_epotential = %.*Le;\n", DECIMAL_DIG, SI2AU_epotential);
   printf("// Electric dipole moment conversion\n");
   long double AU2SI_edipole = electron_charge*AU2SI_length;
   printf("const double AU2SI_edipole = %.*Le;\n", DECIMAL_DIG, AU2SI_edipole);
   long double SI2AU_edipole = 1.0L/AU2SI_edipole;
   printf("const double SI2AU_edipole = %.*Le;\n", DECIMAL_DIG, SI2AU_edipole);
   return 0;
}
