#include "funs.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void create_directory(const char* name)
{
    struct stat st = {0};
    if (stat(name, &st) == -1) {
        mkdir(name, 0700);
    }
}

double noise()
{
    return 2. * (double)(rand() / (RAND_MAX + 1.)) - 1.;
}

double max(double* vec, size_t size)
{
    double maxn = vec[0];
    for(size_t i=0; i<size; i++)
    {
        if(vec[i]>maxn) maxn = vec[i];
    }
    return maxn;
}

void generate_signal(double* y, size_t size)
{
    srand(time(NULL));
    double omega = 4*M_PI / size;

    for(size_t i=0; i<size; i++)
    {
        y[i] = sin(omega*i) + sin(2*omega*i) + sin(3*omega*i) + noise();
    }
}

void generate_pure_signal(double* y, size_t size)
{
    double omega = 4*M_PI / size;

    for(size_t i=0; i<size; i++)
    {
        y[i] = sin(omega*i) + sin(2*omega*i) + sin(3*omega*i);
    }
}

void save_to_file(double *y, size_t size, const char* filename, double threshold)
{
    create_directory("data");
    char *path = malloc(strlen("data")+strlen(filename)+2);
    strcpy(path,"data/");
    strcat(path,filename);
    FILE *f = fopen(path,"w");

    if(threshold==0)
    {
        for(size_t i=0; i<size; i++)
        {
            fprintf(f,"%lu\t%lf\n",i,y[i]);
        }
    }
    else
    {
        for(size_t i=0; i<size; i++)
        {
            fprintf(f,"%lu\t%lf\t%lf\n",i,y[i],threshold);
        }
    }

    fclose(f);
    free(path);
}

void save_complex_to_file(double *y, size_t size, const char* filename, double threshold)
{
    create_directory("data");
    char *path = malloc(strlen("data")+strlen(filename)+2);
    strcpy(path,"data/");
    strcat(path,filename);
    FILE *f = fopen(path,"w");

    if(threshold==0)
    {
        for(size_t i=0; i<size; i++)
        {
            fprintf(f,"%lu\t%lf\t%lf\n",i,y[2*i],y[2*i+1]);
        }
    }
    else
    {
        for(size_t i=0; i<size; i++)
        {
            fprintf(f,"%lu\t%lf\t%lf\t%lf\n",i,y[2*i],y[2*i+1],threshold);
        }
    }

    fclose(f);
    free(path);
}

double* alloc_complex_vector(double* y, size_t size)
{
    double *new_vector = malloc(2*size*sizeof(double));

    for(size_t i=0; i<size; i++)
    {
        new_vector[2*i] = y[i];
        new_vector[2*i+1] = 0;
    }

    return new_vector;
}

void calc_modules(double* mods, size_t mods_size, double *complex)
{
    for(size_t i=0; i<mods_size; i++)
    {
        mods[i] = sqrt( pow(complex[2*i],2) + pow(complex[2*i+1],2) );
    }
}

void discriminate_complex(double *complex, size_t size, double threshold)
{
    double* mods = malloc(size/2*sizeof(double));
    calc_modules(mods, size/2, complex);
    for(size_t i=0; i<size/2; i++)
    {
        if (mods[i]<threshold)
        {
            complex[2*i] =0;
            complex[2*i+1] = 0;
        }
    }
    free(mods);
}

void normalize(double* y,size_t size, double factor)
{
    for(size_t i=0; i<size; i++)
    {
      y[i] /= factor;
    }
}
