// całkowanie metodą Simphsona funkcji postaci x^m*sin(kx) w przedziale [0,PI]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double, double, double);
double factorial(int);
double calka_dokladna(double, double, double, double, size_t, const char*);
double calka_simpsona(double, double, double, double, int, const char*);

int main()
{
    double mk[] = {0,1,1,1,5,5};
    size_t nodes[] = {10,20,50,100,200};
    
    double xStart = 0;
    double xStop = M_PI;
    
    double a1 = calka_dokladna(mk[0], mk[1], xStart, xStop, 30, "calka_1a.dat");
    double a2 = calka_dokladna(mk[2], mk[3], xStart, xStop, 30, "calka_1b.dat");
    double a3 = calka_dokladna(mk[4], mk[5], xStart, xStop, 30, "calka_1c.dat");
    double results[] = {a1,a2,a3};

    int i = 0;
    while (i<6)
    {
        char* filename;
        switch(i)
        {
            case 0: filename = "calka_2a.dat"; break;
            case 2: filename = "calka_2b.dat"; break;
            case 4: filename = "calka_2c.dat"; break;
        }

        FILE *file = fopen(filename,"w");
        
        size_t nodeIdx = 0;
        fprintf(file, "m=%.0lf\t k=%.0lf\n", mk[i], mk[i+1]);
        fprintf(file, "n\twynik\n");
        while(nodeIdx < 5)
        {
            double result = calka_simpsona(mk[i], mk[i+1], xStart, xStop, nodes[nodeIdx], filename);
            fprintf(file, "%lu\t%.20lf\t%.20lf\n", nodes[nodeIdx], result, fabs(result - results[i/2]));
            nodeIdx++;
        }

        fclose(file);
        i += 2;
    }

    return 0;
}

double f(double m, double k, double x) 
{ 
    return pow(x,m) * sin(k*x); 
}

double factorial(int n)
{
    double result = 1;
    for(int i=1; i<=n; i++)
    {
        result *= i;
    }
    //printf("%d\t%lf\n",n,result);
    return result;
}

double calka_dokladna(double m, double k, double a, double b, size_t precision, const char* filename)
{
    FILE* file = fopen(filename,"w");
    fprintf(file,"i\tsuma\n");
    double sum = 0;
    for(int i=0; i<precision; i++)
    {
        double numerator = (pow(k*b, 2*i+m+2) - pow(k*a, 2*i+m+2))* (i%2==0 ? 1 : -1);
        double denominator = pow(k,m+1) * factorial(2*i+1) * (2*i + m + 2);
        
        sum += numerator / denominator;
        
        fprintf(file,"%d\t%.20lf\n",i+1,sum);
    }
    fclose(file);
    return sum;
}

double calka_simpsona(double m, double k, double a, double b, int n, const char* filename)
{
    double sum, sumEven,sumOdd,h,x;

    sumEven = 0; sumOdd = 0;
    h = (b - a) / n;
    for(int i=1; i<=n; i++)
    {
        x = a + i * h;
        sumOdd += f(m,k,x - h/2.);
        if (i!=n) sumEven += f(m,k,x);
    }
    sum = h / 6. * ( f(m,k,a) + f(m,k,b) + 2.*sumEven + 4.*sumOdd );
    return sum;
}