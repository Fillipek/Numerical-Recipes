#include "funs.h"

#include <stdio.h>

int main()
{
    double result = findFunMin(-0.5, 1, 0.000001, f1, "wyniki1.dat");
    printf("result = %.10lf\n",result);
    return 0;
}