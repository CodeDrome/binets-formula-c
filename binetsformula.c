
#include<stdio.h>
#include<math.h>

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void print_fibonacci_to(int n);
int binets_formula(int n);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
void main(void)
{
    puts("-------------------");
    puts("| codedrome.com   |");
    puts("| Binet's Formula |");
    puts("-------------------\n");

    print_fibonacci_to(8);
}

//--------------------------------------------------------
// FUNCTION print_fibonacci_to
//--------------------------------------------------------
void print_fibonacci_to(int n)
{
    if(n < 2)
    {
        printf("term must be >= 2\n");
    }
    else
    {
        int F_n_minus_2 = 0;
        int F_n_minus_1 = 1;
        int F_n = 0;
        int F_n_Binet = 0;

        printf("Calculating Fibonacci numbers\nsequentially and using Binet's Formula\n\n");
        printf(" Term          Seq        Binet  OK?\n------------------------------------\n");

        printf("    0          %3d            ~   ~\n", F_n_minus_2);
        printf("    1          %3d            ~   ~\n", F_n_minus_1);

        for(int i = 2; i <= n; i++)
        {
            F_n = F_n_minus_2 + F_n_minus_1;

            F_n_Binet = binets_formula(i);

            printf("%5d %12d %12d", i, F_n, F_n_Binet);

            if(F_n_Binet == F_n)
                printf("   Y\n");
            else
                printf("   N\n");

            F_n_minus_2 = F_n_minus_1;
            F_n_minus_1 = F_n;
        }
    }
}

//--------------------------------------------------------
// FUNCTION binets_formula
//--------------------------------------------------------
int binets_formula(int n)
{
    // as we use sqrt(5), pre-calculate it to make the formula look neater
    double sqrt5 = sqrt(5);

    int F_n = ( pow((1 + sqrt5), n) - pow((1 - sqrt5), n) ) / ( pow(2, n) * sqrt5 );

    return F_n;
}
