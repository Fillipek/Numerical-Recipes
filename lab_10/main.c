#include "funs.h"

#include <stdio.h>

int main()
{
    double xMin = -0.5, xMax = 1.;
    double epsilon = 0.000001;

    findFunMinGolden(xMin, xMax, 
                     epsilon, f, 
                     "wynikiGf.dat", 
                     -0.1673198);
    findFunMinGolden(xMin, xMax,
                     epsilon, g,
                     "wynikiGg.dat",
                     0.);
    findFunMinTriple(xMin, xMax,
                     epsilon, f,
                     "wynikiTf.dat",
                     -0.1673198);
    findFunMinTriple(xMin, xMax,
                     epsilon, g,
                     "wynikiTg.dat",
                     0.);
    return 0;
}