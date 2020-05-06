#ifndef FUNS_H
#define FUNS_H

// Finds the minimal value of function f in range [xa, xb] 
// with given precision epsilon. 
// Results will be savd in file "filename".
// it also needs precise value to compare
double findFunMin(double xa, double xb, double epsilon, double (*f)(double), const char *filename, double cmpVal);

//ln(x^5 + 3x^2 + x + 9)
double f(double x);

#endif