#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <string.h>
#include <float.h>
#include <math.h>
#include <argp.h>
#include <gmp.h>

// cmd opt parsing
typedef struct {
   long int l; // degree of spherical harmonic
   bool l_present;
   long int m; // order of spherical harmonic
   bool m_present;
   char *filename_base;
   bool filename_base_present;
} cmd_options_t;

enum cmd_opt_IDs {
   l_ID = 1024, // degree of spherical harmonic
   m_ID,        // order of spherical harmonic
   filename_base_ID
};

const char *argp_program_version = "v0.1";
const char *argp_program_bug_address = "whatever@whatever.org";
//const char *argp_program_version = PACKAGE_VERSION;
//const char *argp_program_bug_address = PACKAGE_BUGREPORT;
/* Program documentation. */
static char doc[] = "Generate C-code to evaluate cartesian spherical harmonics.";
static struct argp_option possible_options[] = {
   {
      "l",
      l_ID,
      "l",
      0,
      "degree of spherical harmonic. [0, inf)",
      0
   },{
      "m",
      m_ID,
      "m",
      0,
      "order of spherical harmonic. [-l, l]",
      0
   },{
      "filebase",
      filename_base_ID,
      "<name>",
      0,
      "filename base for header and source file <name>.c and <name>.h",
      0
   },{
      0, 0, 0, 0, 0, 0
   }
};

// Option parsing function
static error_t parse_cmd_options(int key, char *arg, struct argp_state *state) {
   // Get the input argument from argp_parse, which we
   // know is a pointer to our arguments structure. */
   cmd_options_t *options = state->input;

   switch (key) {
      case l_ID:
         options->l = atol(arg);
         options->l_present = true;
         break;
      case m_ID:
         options->m = atol(arg);
         options->m_present = true;
         break;
      case filename_base_ID:
         options->filename_base = arg;
         options->filename_base_present = true;
         break;
      case ARGP_KEY_ARG:
         if (state->arg_num > 0) {
            argp_usage(state);
         }
         break;
      default:
         return ARGP_ERR_UNKNOWN;
         break;
   }

   return 0;
}

// Our argp parser.
static struct argp argp = {possible_options,
                           parse_cmd_options,
                           NULL,
                           doc,
                           NULL, NULL, NULL};

// easy interface to command line option parsing
cmd_options_t parse_command_line_options(int argc, char **argv) {
   cmd_options_t options;
   // set default values
   options.l = 0;             // degree of spherical harmonic
   options.l_present = false;
   options.m = 0;             // order of spherical harmonic
   options.m_present = false;
   options.filename_base = NULL;
   options.filename_base_present = false;

   // actually parse the arguments
   argp_parse(&argp, argc, argv, 0, 0, &options);

   return options;
}

// Some useful GMP function definitions
void factorial(long int n, mpq_t fact) {
   mpq_t tmp;
   mpq_init(tmp);

   mpq_set_si(fact, 1, 1);
   for (long int i=1; i<=n; i++) {
      mpq_set_si(tmp, i, 1);
      mpq_mul(fact, fact, tmp);
   }

   mpq_clear(tmp);
}

void binomial_coefficient(long int n, long int k, mpq_t bc) {
   // n!/(k!*(n-k)!)
   mpq_t tmp;
   mpq_init(tmp);

   factorial(n, bc);
   factorial(k, tmp);
   mpq_div(bc, bc, tmp);
   factorial(n-k, tmp);
   mpq_div(bc, bc, tmp);

   mpq_clear(tmp);
}

void mpq_pow(mpq_t base, long int exponent, mpq_t power) {
   if (exponent == 0) {
      mpq_set_si(power, 1, 1);
      return;
   }
   long int tmp_exponent = exponent > 0 ? exponent : -exponent;
   mpq_set(power, base);
   for (long int i=1; i<tmp_exponent; i++) {
      mpq_mul(power, power, base);
   }
   if (exponent < 0) {
      mpq_inv(power, power);
   }
}

void remove_special_chars(char *string) {
   if (string != NULL) {
      while (*string != '\0') {
         if (!isalnum(*string)) {
            *string = '_';
         }
         string++;
      }
   }
}

void string_toupper(char *string) {
   if (string != NULL) {
      while (*string != '\0') {
         *string = toupper(*string);
         string++;
      }
   }
}

void write_header_file(long int l, long int m, char *filenamebase) {
   int filenamelen = strlen(filenamebase) + 3;
   char *header_filename = (char*) malloc(filenamelen*sizeof(char));
   strcpy(header_filename, filenamebase);
   strcat(header_filename, ".h");

   FILE *headerfile = fopen(header_filename, "w");

   // replace characters and make uppercase
   remove_special_chars(header_filename);
   string_toupper(header_filename);

   // print the header guard
   fprintf(headerfile, "#ifndef %s\n", header_filename);
   fprintf(headerfile, "#define %s\n", header_filename);


   // write function declaration
   char *msign = "";
   msign = m < 0 ? "m" : msign;
   msign = m > 0 ? "p" : msign;
   m = m < 0 ? -m : m;

   fprintf(headerfile, "\n");
   fprintf(headerfile,
           "double spherical_harmonics_l%ld_m%s%ld"
           "(double x, double y, double z);\n",
           l, msign, m);
   fprintf(headerfile, "\n");

   // end header guard
   fprintf(headerfile, "#endif\n");

   fclose(headerfile);
   free(header_filename);
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

void write_powers(FILE *file, char *var, long int maxpow) {
   long int absmaxpow = maxpow > 0 ? maxpow : -maxpow;
   fprintf(file, "   double %s_pow2 = %s * %s;\n", var, var, var);
   if (absmaxpow%2 == 0) {
      for (long int ipow=4; ipow<=absmaxpow; ipow+=2) {
         fprintf(file, "   double %s_pow%ld = %s_pow%ld * %s_pow2;\n",
                var, ipow, var, ipow-2, var);
      }
   } else {
      fprintf(file, "   double %s_pow3 = %s_pow2 * %s;\n", var, var, var);
      for (long int ipow=5; ipow<=absmaxpow; ipow+=2) {
         fprintf(file, "   double %s_pow%ld = %s_pow%ld * %s_pow2;\n",
                var, ipow, var, ipow-2, var);
      }
   }
   fprintf(file, "\n");
}

void write_rpowers(FILE *file, long int l, long int m) {
   long int absm = m > 0  ? m : -m;
   if (absm < 2) {
      fprintf(file, "   double r_pow2 = x*x + y*y");
   } else {
      fprintf(file, "   double r_pow2 = x_pow2 + y_pow2");
   }
   if (l-absm > 1) {
      fprintf(file, " + z_pow2");
   } else {
      fprintf(file, " + z*z");
   }
   fprintf(file, ";\n");
   fprintf(file, "   double r = sqrt(r_pow2);\n");

   for (long int ipow=4; ipow<=l; ipow+=2) {
      fprintf(file, "   double r_pow%ld = r_pow%ld * r_pow2;\n",
              ipow, ipow-2);
   }
   if (l%2 != 0 && l > 1) {
      fprintf(file, "   double r_pow%ld = r_pow%ld * r;\n", l, l-1);
   }

   fprintf(file, "\n");
}

void write_source_file(long int l, long int m, char *filenamebase) {
   int filenamelen = strlen(filenamebase) + 3;
   char *source_filename = (char*) malloc(filenamelen*sizeof(char));
   strcpy(source_filename, filenamebase);
   strcat(source_filename, ".c");

   FILE *sourcefile = fopen(source_filename, "w");

   // write include files
   fprintf(sourcefile, "#include <math.h>\n");
   fprintf(sourcefile, "\n");

   // write function declaration
   char *msign = "";
   msign = m < 0 ? "m" : msign;
   msign = m > 0 ? "p" : msign;
   long int absm = m < 0 ? -m : m;

   fprintf(sourcefile,
           "double spherical_harmonics_l%ld_m%s%ld"
           "(double x, double y, double z){\n",
           l, msign, absm);

   // compute powers of x, y, z
   if (absm > 1) {
      if (absm%2 == 0) {
         if (m > 0) {
            write_powers(sourcefile, "x", absm);
            write_powers(sourcefile, "y", absm);
         } else {
            write_powers(sourcefile, "x", absm-1);
            write_powers(sourcefile, "y", absm-1);
         }
      } else {
         if (m > 0) {
            write_powers(sourcefile, "x", absm);
            write_powers(sourcefile, "y", absm-1);
         } else {
            write_powers(sourcefile, "x", absm-1);
            write_powers(sourcefile, "y", absm);
         }
      }
   }
   if (l-absm > 1) {
      write_powers(sourcefile, "z", l-absm);
   }

   // compute powers of r
   if (l > 0) {
      write_rpowers(sourcefile, l, m);
   }

   // compute PI(l,m,z)
   if (l != 0) {
      fprintf(sourcefile,
              "   double PIlmz = 0.0;\n");
      for (long int k=0; k<=(l-absm)/2; k++) {
         fprintf(sourcefile,
                 "   PIlmz %s ", k%2 == 0 ? "+=" : "-=");
         // compute product of prefactors
         mpq_t prefactor_mpq;
         mpq_init(prefactor_mpq);
         // compute power of two
         mpq_t base;
         mpq_init(base);
         mpq_set_si(base, 2, 1);
         mpq_t pow2;
         mpq_init(pow2);
         mpq_pow(base, -l, pow2);
         mpq_set(prefactor_mpq, pow2);
         mpq_clear(base);
         mpq_clear(pow2);
   
         // first binomial coefficient
         mpq_t binomial_coeff_lk;
         mpq_init(binomial_coeff_lk);
         binomial_coefficient(l, k, binomial_coeff_lk);
         mpq_mul(prefactor_mpq, prefactor_mpq, binomial_coeff_lk);
         mpq_clear(binomial_coeff_lk);
   
         // second binomial coefficient
         mpq_t binomial_coeff_lkl;
         mpq_init(binomial_coeff_lkl);
         binomial_coefficient(2*(l-k), l, binomial_coeff_lkl);
         mpq_mul(prefactor_mpq, prefactor_mpq, binomial_coeff_lkl);
         mpq_clear(binomial_coeff_lkl);
   
         // factorial fraction will be 1 for m==0
         if (m != 0) {
            mpq_t factorial_lk;
            mpq_init(factorial_lk);
            factorial(l-2*k, factorial_lk);
            mpq_t factorial_lkm;
            mpq_init(factorial_lkm);
            factorial(l-2*k-absm, factorial_lkm);
            mpq_mul(prefactor_mpq, prefactor_mpq, factorial_lk);
            mpq_div(prefactor_mpq, prefactor_mpq, factorial_lkm);
            mpq_clear(factorial_lk);
            mpq_clear(factorial_lkm);
         }
   
         double prefactor_d = mpq_get_d(prefactor_mpq);
         mpq_clear(prefactor_mpq);
         fprintf(sourcefile,
                 "%.*le",DECIMAL_DIG, prefactor_d);

         if (2*k > 1) {
            fprintf(sourcefile,
                    " * r_pow%ld", 2*k);
         }
         if (l-2*k-absm == 1) {
            fprintf(sourcefile,
                    " * z");
         } else if (l-2*k-absm > 1) {
            fprintf(sourcefile,
                    " * z_pow%ld", l-2*k-absm);
         }

   
         fprintf(sourcefile, ";\n");
      }

      // calculate prefactor of PIlmz
      if (m != 0) {
         mpq_t factorial_lmm;
         mpq_init(factorial_lmm);
         factorial(l-absm, factorial_lmm);
         mpq_t factorial_lpm;
         mpq_init(factorial_lpm);
         factorial(l+absm, factorial_lpm);
         mpq_t prefactor_mpq;
         mpq_init(prefactor_mpq);
         mpq_set(prefactor_mpq, factorial_lmm);
         mpq_div(prefactor_mpq, prefactor_mpq, factorial_lpm);
         double prefactor_d = sqrt(mpq_get_d(prefactor_mpq));
         mpq_clear(factorial_lmm);
         mpq_clear(factorial_lpm);
         mpq_clear(prefactor_mpq);
         fprintf(sourcefile,
                 "   PIlmz *= %.*le;\n",
                 DECIMAL_DIG, prefactor_d);

      }
      fprintf(sourcefile, "\n");
   }

   // compute A(m,x,y)
   if (m > 0) {
      fprintf(sourcefile,
              "   double Amxy = 0.0;\n");
      for (long int p=0; p<=m; p++) {
         if (Amxy_prefactor(m, p) != 0) {
            // binomial prefactor
            mpq_t binomial_coeff_mpq;
            mpq_init(binomial_coeff_mpq);
            binomial_coefficient(m, p, binomial_coeff_mpq);
            double binomial_coeff_d = mpq_get_d(binomial_coeff_mpq);
            mpq_clear(binomial_coeff_mpq);
   
            fprintf(sourcefile,
                    "   Amxy %s ", Amxy_prefactor(m, p) > 0 ? "+=" : "-=");
            fprintf(sourcefile,
                    "%.*le",DECIMAL_DIG, binomial_coeff_d);
            if (p == 1) {
               fprintf(sourcefile,
                       " * x");
            } else if (p > 1) {
               fprintf(sourcefile,
                       " * x_pow%ld", p);
            }
            if (m-p == 1) {
               fprintf(sourcefile,
                       " * y");
            } else if (m-p > 1) {
               fprintf(sourcefile,
                       " * y_pow%ld", m-p);
            }
            fprintf(sourcefile, ";\n");
         }
      }
      fprintf(sourcefile, "\n");
   }

   // compute B(m,x,y)
   if (m < 0) {
      fprintf(sourcefile,
              "   double Bmxy = 0.0;\n");
      for (long int p=0; p<=absm; p++) {
         if (Bmxy_prefactor(absm, p) != 0) {
            // binomial prefactor
            mpq_t binomial_coeff_mpq;
            mpq_init(binomial_coeff_mpq);
            binomial_coefficient(absm, p, binomial_coeff_mpq);
            double binomial_coeff_d = mpq_get_d(binomial_coeff_mpq);
            mpq_clear(binomial_coeff_mpq);
   
            fprintf(sourcefile,
                    "   Bmxy %s ", Bmxy_prefactor(absm, p) > 0 ? "+=" : "-=");
            fprintf(sourcefile,
                    "%.*le",DECIMAL_DIG, binomial_coeff_d);
            if (p == 1) {
               fprintf(sourcefile,
                       " * x");
            } else if (p > 1) {
               fprintf(sourcefile,
                       " * x_pow%ld", p);
            }
            if (absm-p == 1) {
               fprintf(sourcefile,
                       " * y");
            } else if (absm-p > 1) {
               fprintf(sourcefile,
                       " * y_pow%ld", absm-p);
            }
            fprintf(sourcefile, ";\n");
         }
      }
      fprintf(sourcefile, "\n");
   }

   // compute Norm
   double norm;
   if (m == 0) {
      norm = sqrt((2*l+1)/(4*M_PI));
   } else {
      norm = sqrt((2*l+1)/(2*M_PI));
   }
   
   // combine everything
   fprintf(sourcefile,
           "   return ");
   fprintf(sourcefile,
           "%.*le", DECIMAL_DIG, norm);
   if (l != 0) {
      fprintf(sourcefile,
              " * PIlmz");
   }
   if (m > 0) {
      fprintf(sourcefile,
              " * Amxy");
   }
   if (m < 0) {
      fprintf(sourcefile,
              " * Bmxy");
   }
   if (l == 1) {
      fprintf(sourcefile,
              " / r");
   } else if (l > 1) {
      fprintf(sourcefile,
           " / r_pow%ld", l);
   }
   fprintf(sourcefile,
           ";\n");

   // close function
   fprintf(sourcefile, "}\n");

   fclose(sourcefile);
   free(source_filename);
}



int main(int argc, char **argv) {

   cmd_options_t options = parse_command_line_options(argc, argv);
   // sanity check for l
   if (options.l_present) {
      if (options.l < 0) {
         fprintf(stderr, "Value of \"l\" needs to be zero or positive. Is %ld.\n", options.l);
         return EXIT_FAILURE;
      }
   } else {
      fprintf(stderr, "Need value for \"l\".\n");
      return EXIT_FAILURE;
   }

   // sanity check for m
   if (options.m_present) {
      if (options.m > options.l || options.m < -options.l) {
         fprintf(stderr, "Value of \"m\" needs to from the interval [-l,l]. Is %ld.\n", options.m);
         return EXIT_FAILURE;
      }
   } else {
      fprintf(stderr, "Need value for \"m\".\n");
      return EXIT_FAILURE;
   }

   // sanity check for filename_base
   if (options.filename_base_present) {
      if (strlen(options.filename_base) == 0) {
         fprintf(stderr, "Invalid filename base given.\n");
         return EXIT_FAILURE;
      }
   } else {
      fprintf(stderr, "Need filename base\n");
      return EXIT_FAILURE;
   }

   // write the header file
   write_header_file(options.l, options.m, options.filename_base);
   write_source_file(options.l, options.m, options.filename_base);

   return EXIT_SUCCESS;
}
