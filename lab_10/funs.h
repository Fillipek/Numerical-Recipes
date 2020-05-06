#ifndef FUNS_H
#define FUNS_H

// Finds the minimal value of function f in range [xa, xb] with given precision epsilon. Relutls will be savd in file "filename"
double findFunMin(double xa, double xb, double epsilon, double (*f)(double), const char *filename);

double f1(double x);

#endif