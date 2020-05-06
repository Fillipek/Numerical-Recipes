#include "funs.h"

#include <stdio.h>
#include <math.h>

double findFunMin(double xa, double xb, double epsilon, double (*f)(double), const char *filename)
{
    const double r = (sqrt(5) - 1.) / 2.;
    const double lambda1 = r * r, lambda2 = r;
    double x1, x2;
    ;
    do
    {
        x1 = xa + lambda1 * (xb - xa);
        x2 = xa + lambda2 * (xb - xa);
        if (f(x2) > f(x1))
        {
            xb = x2;
            printf("zmiana xb = %f\n", xb);
        }
        else
        {
            xa = x1;
            printf("zmiana xa = %f\n", xa);
        }
    } while (fabs(x2 - x1) >= epsilon);

    return (x1 + x2) / 2.;
}

double f1(double x)
{
    return log(pow(x, 5) + 3 * pow(x, 2) + x + 9);
}