#include "funs.h"

#include <stdio.h>

int main()
{
    double result = findFunMin(-0.5, 1, 0.000001, f, "wyniki1.dat", -0.1673198);
    printf("result = %.10lf\n",result);
    return 0;
}