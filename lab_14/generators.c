#include <math.h>
#include "generators.h"

double vec_len(double x, double y, double z)
{
    return sqrt(x * x + y * y + z * z);
}

double generator_1()
{
    double a = 17;
    long int m = pow(2, 13) - 1;
    static long int x = 10;
    x = (long int)(a*x) % m;
    return x / (m + 1.);
}

double generator_2()
{
    double a = 85;
    long int m = pow(2, 13) - 1;
    static long int x = 10;
    x = (long int)(a*x) % m;
    return x / (m + 1.);
}

double generator_3()
{
    long int m = pow(2, 32) - 5;
    double a0 = 1176, a1 = 1476, a2 = 1776;
    static long int x2 = 10, x1 = 10, x0 = 10;
    long int x3 = (long int)(a0*x2 + a1*x1 + a2*x0) % m;
    x0 = x1;
    x1 = x2;
    x2 = x3;
    return x2 / (m+1.);
}

void generator_4(double* x, double* y, double* z)
{
    double u1, u2, u3, u4, len;

    u1 = generator_3();
    u2 = generator_3();
    u3 = generator_3();
    u4 = generator_3();

    *x = sqrt(-2 * log(1 - u1)) * cos(2 * M_PI * u2);
    *y = sqrt(-2 * log(1 - u1)) * sin(2 * M_PI * u2);
    *z = sqrt(-2 * log(1 - u3)) * cos(2 * M_PI * u4);

    len = vec_len(*x, *y, *z);
    *x /= len;
    *y /= len;
    *z /= len;
}
