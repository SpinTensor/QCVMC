#ifndef MP_CONSTS_H
#define MP_CONSTS_H

//Mathematical constants
extern const double halfpi;
extern const double ihalfpi;
extern const double sqrt_halfpi;
extern const double sqrt_ihalfpi;
extern const double pi;
extern const double ipi;
extern const double sqrt_pi;
extern const double sqrt_ipi;
extern const double twopi;
extern const double itwopi;
extern const double sqrt_twopi;
extern const double sqrt_itwopi;
extern const double e;
extern const double ie;
extern const double sqrt_2;
extern const double sqrt_3;
extern const double sqrt_1_2;
extern const double sqrt_1_3;
extern const double sqrt_2_3;
extern const double sqrt_3_2;

//Physical constants
// Speed of light in vacuum [m/s]
extern const double lightspeed;

// Magnetic constant or permeability of vacuum [N/A^2]
extern const double mu_perm;

// Electric constant or permittivity of vacuum [F/m]
extern const double permittivity;

// Planck constant [J*s]
extern const double h_planck;
extern const double h_bar;

// Elementary charge [C]
extern const double electron_charge;

// Electron mass [kg]
extern const double electron_mass;

// Proton mass [kg]
extern const double proton_mass;

// Electron g factor [ ]
extern const double electron_gfactor;

// Fine-structure constant
// finestructure = 0.5*mu_perm*lightspeed*electroncharge^2/h_planck
extern const double finestructure;

// Rydberg constant [1/m]
// rydberg = 0.5*electronmass*lightspeed*finestructure^2/h_planck
extern const double rydberg;

// Avogadro constant [1/mol]
extern const double n_avogadro;

// Boltzmann constant [J/K]
extern const double boltzmann;

//Conversion factors
// Length conversion
extern const double AU2SI_length;
extern const double SI2AU_length;
extern const double AU2angstrom_length;
extern const double angstrom2AU_length;
// Energy conversion
extern const double AU2SI_energy;
extern const double SI2AU_energy;
// Time conversion 
extern const double AU2SI_time;
extern const double SI2AU_time;
// Velocity conversion
extern const double AU2SI_velocity;
extern const double SI2AU_velocity;
// Mass conversion
extern const double AU2SI_mass;
extern const double SI2AU_mass;
extern const double AU2U_mass;
extern const double U2AU_mass;
// Force conversion
extern const double AU2SI_force;
extern const double SI2AU_force;
// Temperature conversion
extern const double AU2SI_temperature;
extern const double SI2AU_temperature;
// Pressure conversion
extern const double AU2SI_pressure;
extern const double SI2AU_pressure;
// Electric field conversion
extern const double AU2SI_efield;
extern const double SI2AU_efield;
// Electric potential conversion
extern const double AU2SI_epotential;
extern const double SI2AU_epotential;
// Electric dipole moment conversion
extern const double AU2SI_edipole;
extern const double SI2AU_edipole;

#endif
