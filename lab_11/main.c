#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>
#include <stdlib.h>
#include "funs.h"

int main(void)
{
    {
        size_t k = 8;
        size_t N = pow(2, k);
        double *y = malloc(N*sizeof(double));
        double *py = malloc(N*sizeof(double));

	      generate_signal(y,N);
        save_to_file(y, N, "8_raw_signal.dat",0);

        generate_pure_signal(py,N);
        save_to_file(py,N,"8_pure_signal.dat",0);

        double *fourier = alloc_complex_vector(y, N);

        gsl_fft_complex_radix2_forward(fourier, 1, N);
        save_complex_to_file(fourier, N, "8_fft_signal.dat",0);

        calc_modules(y, N, fourier);
        save_to_file(y, N, "8_fft_modules.dat",max(y, N) / 2.);

        discriminate_complex(fourier, 2*N, max(y, N) / 2. );

        gsl_fft_complex_radix2_backward(fourier, 1, N);
        normalize(fourier,2*N,N);
        save_complex_to_file(fourier, N, "8_filtered_signal.dat",0);

        free(fourier);
        free(y);
        free(py);
    }

    {
        size_t k = 10;
        size_t N = pow(2, k);
        double *y = malloc(N*sizeof(double));
        double *py = malloc(N*sizeof(double));

	      generate_signal(y,N);
        save_to_file(y, N, "10_raw_signal.dat",0);

        generate_pure_signal(py,N);
        save_to_file(py,N,"10_pure_signal.dat",0);

        double *fourier = alloc_complex_vector(y, N);

        gsl_fft_complex_radix2_forward(fourier, 1, N);
        save_complex_to_file(fourier, N, "10_fft_signal.dat",0);

        calc_modules(y, N, fourier);
        save_to_file(y, N, "10_fft_modules.dat",max(y, N) / 2.);

        discriminate_complex(fourier, 2*N, max(y, N) / 2. );

        gsl_fft_complex_radix2_backward(fourier, 1, N);
        normalize(fourier,2*N,N);
        save_complex_to_file(fourier, N, "10_filtered_signal.dat",0);

        free(fourier);
        free(y);
        free(py);
    }

    {
        size_t k = 12;
        size_t N = pow(2, k);
        double *y = malloc(N*sizeof(double));
        double *py = malloc(N*sizeof(double));

	      generate_signal(y,N);
        save_to_file(y, N, "12_raw_signal.dat",0);

        generate_pure_signal(py,N);
        save_to_file(py,N,"12_pure_signal.dat",0);

        double *fourier = alloc_complex_vector(y, N);

        gsl_fft_complex_radix2_forward(fourier, 1, N);
        save_complex_to_file(fourier, N, "12_fft_signal.dat",0);

        calc_modules(y, N, fourier);
        save_to_file(y, N, "12_fft_modules.dat",max(y, N) / 2.);

        discriminate_complex(fourier, 2*N, max(y, N) / 2. );

        gsl_fft_complex_radix2_backward(fourier, 1, N);
        normalize(fourier,2*N,N);
        save_complex_to_file(fourier, N, "12_filtered_signal.dat",0);

        free(fourier);
        free(y);
    }

    return 0;
}
