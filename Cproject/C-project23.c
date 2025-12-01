// 홍성제
// 사칙연산 계산기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(char* a);
void output(float result);
void compute(char* a, float* num1, float* num2, char* tok, float* result);
int main()
{
    char a[100];
    float num1, num2;
    float result;
    char tok;

    input(a);
    compute(a, &num1, &num2, &tok, &result);
    output(result);

    return 0;
}

void input(char* a)
{
    printf("연산식 입력:");
    scanf("%s", a);
}

void output(float result)
{
    printf("결과 = %f\n", result);
    return;
}

void compute(char* a, float* num1, float* num2, char* tok, float* result)
{
    char* p;

    p = strpbrk(a, "+-*/");

    *tok = *p;

    *p = '\0';
    *num1 = atof(a);
    *num2 = atof(p + 1);

    switch (*tok)
    {
    case '+':
        *result = *num1 + *num2;
        break;

    case '-':
        *result = *num1 - *num2;
        break;

    case '*':
        *result = *num1 * *num2;
        break;

    case '/':
        *result = *num1 / *num2;
        break;

    }
    return;
}