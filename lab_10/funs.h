#ifndef FUNS_H
#define FUNS_H

// Finds the minimal value of function f in range [xa, xb]
// using golden proportion
// with given precision epsilon. 
// Results will be savd in file "filename".
// it also needs precise value to compare
double findFunMinGolden(double xa, double xb, double epsilon, double (*f)(double), const char *filename, double cmpVal);

// Finds the minimal value of function f in range [xa, xb]
// spliting the range to 3 ranges of equal length
// with given precision epsilon.
// Results will be savd in file "filename".
// it also needs precise value to compare
double findFunMinTriple(double xa, double xb, double epsilon, double (*f)(double), const char *filename, double cmpVal);

//ln(x^5 + 3x^2 + x + 9)
double f(double x);

//x^6
double g(double x);

#endif