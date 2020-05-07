#include "funs.h"

#include <stdio.h>

int main()
{
    double epsilon = 0.000001;

    findFunMinGolden(-0.5, 1, 
                     epsilon, f, 
                     "wynikiGf.dat", 
                     -0.1673198);
    findFunMinGolden(-4, 1,
                     epsilon, g,
                     "wynikiGg.dat",
                     0.);
    findFunMinTriple(-0.5, 1,
                     epsilon, f,
                     "wynikiTf.dat",
                     -0.1673198);
    findFunMinTriple(-4, 1,
                     epsilon, g,
                     "wynikiTg.dat",
                     0.);
    return 0;
}