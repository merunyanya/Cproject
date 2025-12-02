
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int input(int* pa, int* pb);
int output(double result1, double result2, double height);
double compute(int* pa, int* pb, double* reuslt1, double* result2);

int main()
{
    int a = 0, b = 0;
    int* pa = &a;
    int* pb = &b;
    double result1 = 0;
    double result2 = 0;
    input(pa, pb);
    double height = compute(pa, pb, &result1, &result2);
    output(result1, result2, height);

    return;
}

int input(int* pa, int* pb)
{
    printf("신장? ");
    scanf("%d", pa);

    printf("체중? ");
    scanf("%d", pb);
    return;
}


int output(double result1, double result2, double normal)
{
    printf("표준체중(kg) : %.1lf'\n", normal);
    printf("신체질량지수 : %.1lf\n", result1);
    printf("비만도(%) : %.1lf", result2);

    return;
}

double compute(int* pa, int* pb, double* result1, double* result2)
{
    double height = (double)*pa / 100;
    double normal = ((double)*pa - 100) * 0.9;
    *result1 = (double)*pb / (height * height);
    *result2 = (((double)*pb - normal) / normal) * 100;

    return normal;
}

