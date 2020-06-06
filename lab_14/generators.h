#ifndef GENERATORS_H
#define GENERATORS_H

double vec_len(double, double, double);

// a = 17
// m = 2^13 - 1
// x_0 = 10
double generator_1();

// a = 85
// m = 2^13 - 1
// x_0 = 10
double generator_2();

// multiplicative generator
// a = [1176, 1476, 1776]
// starting x = 10
double generator_3();

// Box-Muller generator
void generator_4(double*, double*, double*);

#endif
