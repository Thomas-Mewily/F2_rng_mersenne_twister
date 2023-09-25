
#include "__base__.hpp"

double mt_uniform(double a, double b)
{
    return mt_real()*(b-a)+a;
}

double mt_real()
{
    return mt_genrand_real1();
}

double mt_neg_exp(double mean, double rng_val_strictly_positive)
{
    return -mean * log(rng_val_strictly_positive); // zero excluded
}

double mt_neg_exp(double mean)
{
    return mt_neg_exp(mean, 1-mt_genrand_real2()); // zero excluded
}
