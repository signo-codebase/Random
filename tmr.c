#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double TMR(double lm, double lv, double t) {
    double R2su3 = 3 * exp(-2 * lm * t) - 2 * exp(-3 * lm * t);
    return R2su3 * exp(-1 * lv * t) ;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <lambdaModule> <lambdaVotatore> <istante_di_calcolo>\n", argv[0]);
        return 1;
    }

    double arg1 = atof(argv[1]);  // convert argument to float
    double arg2 = atof(argv[2]);
    double arg3 = atof(argv[3]);

    printf( "\nAffidabilità totale: %.20f", TMR(arg1, arg2, arg3) );

    return 0;
}
