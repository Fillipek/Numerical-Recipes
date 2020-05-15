#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>
#include <math.h>
#include <time.h>

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

void save_to_file(double *y, size_t size, const char* filename)
{
    FILE *f = fopen(filename,"w");

    for(size_t i=0; i<size; i++)
    {
        fprintf(f,"%d\t%lf\n",i,y[i]);
    }

    fclose(f);
}

void save_complex_to_file(double *y, size_t size, const char* filename)
{
    FILE *f = fopen(filename,"w");

    for(size_t i=0; i<size; i+=2)
    {
        fprintf(f,"%d\t%lf\t%lf\n",i,y[i],y[i+1]);
    }

    fclose(f);
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

int main(void)
{
    size_t k = 8;
    size_t N = pow(2, k);
    double *y = malloc(N*sizeof(double));
    double *fourier = alloc_complex_vector(y, N);

	generate_signal(y,N);
    save_to_file(y, N, "raw_signal.dat");

    gsl_fft_complex_radix2_forward(fourier, 1, N);
    save_complex_to_file(fourier, 2*N, "fft_signal.dat");

    calc_modules(y, N, fourier);
    save_to_file(y, N, "fft_modules.dat");

    discriminate_complex(fourier, 2*N, max(y, N) / 2. );

    gsl_fft_complex_radix2_backward(fourier, 1, N);
    save_complex_to_file(fourier, 2*N, "filtered_signal.dat");
    
    free(fourier);
    free(y);
    return 0;
}