#include "funs.h"

#include <stdio.h>
#include <math.h>

double findFunMinGolden(double xa, double xb, double epsilon, double (*f)(double), const char *filename, double cmpVal)
{
    FILE *out = fopen(filename,"w");
    const double r = (sqrt(5) - 1.) / 2.;
    const double lambda1 = r * r, lambda2 = r;
    double x1, x2;
    int i = 1;

    fprintf(out, "it. num\t\tcur. est\tdiff\n");

    do
    {
        x1 = xa + lambda1 * (xb - xa);
        x2 = xa + lambda2 * (xb - xa);

        fprintf(out, "%7d\t\t%lf\t%lf\n", i, (xa + xb) / 2., (xa + xb) / 2. - cmpVal);
        
        if (f(x2) > f(x1))
        {
            xb = x2;
        }
        else
        {
            xa = x1;
        }
        i++;
    } while (fabs(x2 - x1) >= epsilon);

    fclose(out);
    return (x1 + x2) / 2.;
}

double findFunMinTriple(double xa, double xb, double epsilon, double (*f)(double), const char *filename, double cmpVal) 
{
    FILE *out = fopen(filename, "w");
    double x1, x2;
    int i = 1;

    fprintf(out, "it. num\t\tcur. est\tdiff\n");

    do
    {
        x1 = xa + (xb - xa)/3.;
        x2 = xa + (xb - xa) / 3. * 2;

        fprintf(out, "%7d\t\t%lf\t%lf\n", i, (xa + xb) / 2., (xa + xb) / 2. - cmpVal);

        if(f(x2) > f(x1)) 
        {
            xb = x2;
        }
        else
        {
            xa = x1;
        }
        i++;
    } while (fabs(x2-x1) >= epsilon);

    fclose(out);
    return (x1 + x2) / 2.;
}

double f(double x)
{
    return log(pow(x, 5) + 3 * pow(x, 2) + x + 9);
}

double g(double x) 
{
    return pow(x,6);
}