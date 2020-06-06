#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "generators.h"

#define N 2000
#define K 10

int main(void)
{
    double *x, *y, *z, *R, *V, *g;
    int *n;
    double u, delta;
    FILE *outf;

    ////////////////////////
    // 1 - GENERATOR 1
    ////////////////////////

    printf("Part 1...");

    x = malloc((N+3)*sizeof(double));
    for(int i=0; i<N+3; i++)
        x[i] = generator_1();

    outf = fopen("generator_1a.dat", "w");
    for(int i=0; i<N; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+1]);
    fclose(outf);

    outf = fopen("generator_1b.dat", "w");
    for(int i=0; i<N+1; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+2]);
    fclose(outf);

    outf = fopen("generator_1c.dat", "w");
    for(int i=0; i<N+3; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+3]);
    fclose(outf);

    free(x);

    printf(" DONE\n");

    ////////////////////////
    // 2 - GENERATOR 2
    ////////////////////////

    printf("Part 2...");

    x = malloc((N+3)*sizeof(double));
    for(int i=0; i<N+3; i++)
        x[i] = generator_2();

    outf = fopen("generator_2a.dat", "w");
    for(int i=0; i<N; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+1]);
    fclose(outf);

    outf = fopen("generator_2b.dat", "w");
    for(int i=0; i<N+1; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+2]);
    fclose(outf);

    outf = fopen("generator_2c.dat", "w");
    for(int i=0; i<N+3; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+3]);
    fclose(outf);

    free(x);

    printf(" DONE\n");

    ////////////////////////
    // 3 - MULTIPLICATIVE GENERATOR
    ////////////////////////

    printf("Part 3...");

    x = malloc((N+3)*sizeof(double));
    for(int i=0; i<N+3; i++)
        x[i] = generator_3();

    outf = fopen("generator_3a.dat", "w");
    for(int i=0; i<N; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+1]);
    fclose(outf);

    outf = fopen("generator_3b.dat", "w");
    for(int i=0; i<N+1; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+2]);
    fclose(outf);

    outf = fopen("generator_3c.dat", "w");
    for(int i=0; i<N+3; i++)
        fprintf(outf, "%lf\t%lf\n", x[i], x[i+3]);
    fclose(outf);

    free(x);

    printf(" DONE\n");

    ////////////////////////
    // 4 - SPHERE
    ////////////////////////

    printf("Part 4...");

    outf = fopen("generator_4a.dat", "w");
    x = malloc(N * sizeof(double));
    y = malloc(N * sizeof(double));
    z = malloc(N * sizeof(double));

    for(int i=1; i<N; i++)
    {
        generator_4(x+i, y+i, z+i);
        fprintf(outf, "%lf\t%lf\t%lf\n", x[i], y[i], z[i]);
    }

    fclose(outf);

    printf(" DONE\n");

    ////////////////////////
    // 5 - BALL
    ////////////////////////

    printf("Part 5...");

    outf = fopen("generator_4b.dat", "w");

    for(int i=1; i<N; i++)
    {
        u = sqrt(generator_3());
        x[i] *= u;
        y[i] *= u;
        z[i] *= u;
        fprintf(outf, "%lf\t%lf\t%lf\n", x[i], y[i], z[i]);
    }

    fclose(outf);

    printf(" DONE\n");

    ////////////////////////
    // 6 - BALL CHECK
    ////////////////////////

    printf("Part 6...");

    outf = fopen("nj_gj.dat", "w");
    delta = 1. / K;
    n = calloc((K+1), sizeof(int));
    R = malloc( (K+1) * sizeof(double));
    V = malloc( (K+1) * sizeof(double));
    g = malloc( (K+1) * sizeof(double));

    for(int i=0; i<N; i++)
    {
        int j = (int)(vec_len(x[i], y[i], z[i]) / delta) + 1;
        n[j]++;
    }

    for(int j=1; j<=K; j++)
    {
        R[j] = delta * j;
        R[j-1] = delta * (j-1);
        V[j] = 4. / 3. * M_PI * pow(R[j], 3);
        V[j-1] = 4. / 3. * M_PI * pow(R[j-1], 3);
        g[j] = n[j] / (V[j] - V[j-1]);
        fprintf(outf, "%d\t%lf\n", n[j], g[j]);
    }

    fclose(outf);
    free(n);
    free(V);
    free(R);
    free(g);
    free(x);
    free(y);
    free(z);

    printf(" DONE\n");

    printf("All OK\n");

    return 0;
}
