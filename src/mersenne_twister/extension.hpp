#ifndef mersenne_twister_extension
#define mersenne_twister_extension

#include "__base__.hpp"
#include "../betterCPP/__base__.hpp"

double mt_uniform(double a, double b);
double mt_real();
double mt_neg_exp(double mean);
double mt_neg_exp(double mean, double rng_val_strictly_positive);


#endif