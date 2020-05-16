#ifndef FUNS_H
#define FUNS_H

#include <stdlib.h>

void create_directory(const char*);
double noise();
double max(double*, size_t);
void generate_signal(double*, size_t);
void save_to_file(double *, size_t, const char*);
void save_complex_to_file(double *, size_t, const char*);
double* alloc_complex_vector(double*, size_t);
void calc_modules(double*, size_t, double *);
void discriminate_complex(double *, size_t, double);

#endif