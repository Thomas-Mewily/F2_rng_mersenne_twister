#include "__base__.hpp"

void verify_uniform(double mini, double maxi, usize nb_repetition)
{
    repeat(i, nb_repetition)
    {
        double r = mt_uniform(mini, maxi);
        check(r >= mini && r <= maxi);
    }
}

void q2_uniform()
{
    double mini = -89.2;
    double maxi = 56.7;
    verify_uniform(mini, maxi, 10000);

    double r = mt_uniform(mini, maxi);
    printf("valeur aléatoire entre [%9.7lf, %9.7lf] : %9.7lf\n\n", mini, maxi, r);
}

int random_index(double proba[], usize size)
{
    double r = mt_real();
    double c = 0;

    repeat(i, size)
    {
        c += proba[i];
        if(r <= c)
        {
            return i;
        }
    }
    crash("not possible");
}

void simulate_class(usize nb_person[], double proba[], usize size, usize nb_repetition)
{
    repeat(i, nb_repetition)
    {
        nb_person[random_index(proba, size)]++;
    }
}

void debug_class(double proba[], usize size, usize nb_repetition)
{
    usize* nb_person = make_array(usize, size);
    repeat(i, size){ nb_person[i] = 0; }

    simulate_class(nb_person, proba, size, nb_repetition);
    printf("class | proba   |     nb     (%%)\n");
    repeat(i, size)
    {
        printf("%3" usize_format " : %9.7lf : %9" usize_format " (%9.7lf %%)\n", i, proba[i], nb_person[i], nb_person[i]/(double)nb_repetition*100);
    }
    printf("\n");
    free(nb_person);
}

void q3_discrete_empirical_distributions()
{
    double proba[] = {0.5, 0.15, 0.35};
    usize  proba_size = sizeof(proba)/sizeof(proba[0]);
    
    debug_class(proba, proba_size, 1000);
    debug_class(proba, proba_size, 1000000);
}

double average(usize nb_repetition)
{
    double av = 0;
    repeat(i, nb_repetition)
    {
        av += mt_neg_exp(11);
    }
    return av / nb_repetition; 
}

void test_continuous_distributions(usize nb_repetition)
{
    #define nb_person_size (17+9)
    usize nb_person[nb_person_size];
    usize s = nb_person_size;

    repeat(i, s){nb_person[i] = 0; }

    repeat(i, nb_repetition)
    {
        usize idx = (int)mt_neg_exp(10);
        if(idx >= s) { idx=s; }

        nb_person[idx]++;
    }
    printf("test_continuous_distributions with %" usize_format " repetition : nb | %% \n", nb_repetition);
    repeat(i, s-1)
    {
        printf(" = %2" usize_format " : %7" usize_format " %9.7lf %%\n", i, nb_person[i], nb_person[i]/(double)nb_repetition*100);
    }
    printf(">= %2" usize_format " : %7" usize_format " %9.7lf %%\n", s-1, nb_person[s-1], nb_person[s-1]/(double)nb_repetition*100);

    printf("\n");
}

void q4_continuous_distributions()
{
    printf("mt_neg_exp(11) = %lf\n", mt_neg_exp(11));

    usize nb_repetition = 1000;
    printf("average mt_neg_exp(11) for %" usize_format " repetitions = %lf\n", nb_repetition, average(nb_repetition));
    nb_repetition = 1000000;
    printf("average mt_neg_exp(11) for %" usize_format " repetitions = %lf\n", nb_repetition, average(nb_repetition));
    printf("\n");

    test_continuous_distributions(1000);
    test_continuous_distributions(1000000);
}

void dice_distribution(usize nb_repetition, usize nb_lance_sum)
{
    usize sum_max = 6*nb_lance_sum+1;
    usize* sum = make_array(usize, sum_max);

    repeat(i, sum_max) { sum[i] = 0; }

    repeat(i, nb_repetition)
    {
        usize s = 0;
        repeat(j, nb_lance_sum)
        {
            s += mt_genrand_int32()%6+1;
        }
        sum[s]++;
    }

    usize maxi = 0;
    repeat(i, sum_max)
    {
        maxi = max(sum[i], maxi);
    }

    printf("(%" usize_format " lancés sommé) * (%" usize_format " simulation)\n", nb_lance_sum, nb_repetition);
    repeat(i, sum_max)
    {
        if(i < nb_lance_sum) { continue;}
        printf("somme = %3" usize_format", %5" usize_format ", %9.7lf%% : ", i, sum[i], sum[i]/(double)nb_repetition*100);
        usize nb_hash = sum[i]*64/maxi;
        repeat(_, nb_hash){ printf("#"); }
        printf("\n");
    }
    printf("\n");
    free(sum);
}

void q5_simulating_non_reversible_laws()
{
    dice_distribution(1000000, 20);
}

void q6_libs()
{
    /*
        java : https://apps.dtic.mil/sti/tr/pdf/ADA459649.pdf
        Hydra: A Java library for Markov Chain Monte Carlo

        C++ : https://www.osti.gov/servlets/purl/1658686
        Generation of Reversible C++ Code for Optimistic Parallel Discrete Event Simulation
    */
}

int main(int argc, char const* argv[])
{
    unused(argc);
    unused(argv);
    printf("%sCompilation%s de %s \n", COLOR_DEBUG_CATEGORY, COLOR_RESET, current_time);
    verify();

    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    mt_init_by_array(init, length);

    q2_uniform();
    q3_discrete_empirical_distributions();
    q4_continuous_distributions();
    q5_simulating_non_reversible_laws();
    q6_libs();


    memory_printf_final();
    return EXIT_SUCCESS;
}