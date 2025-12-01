// 홍성제
// 특정일의 요일 계산

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* year, int* month, int* day);
int computeyear(int year, int month, int day, int* a, int* b);
int computemonth(int year, int month, int day, int* a, int* b, int arr1[], int arr2[]);
int computeday(int a, int b, int month, int day, int month_result);
void output(int n);

int main()
{
    int arr1[12] = { 31, 29, 31, 30 ,31 ,30, 31, 31, 30 ,31 ,30 ,31 }; //윤년
    int arr2[12] = { 31, 28, 31, 30 ,31 ,30, 31, 31, 30 ,31 ,30 ,31 }; //평년
    int year = 0, month = 0, day = 0;
    int a = 0; int b = 0;
    int year_result = 0;
    int month_result = computemonth(year, month, day, &a, &b, arr1, arr2);
    int n = 0;

    input(&year, &month, &day);
    computeyear(year, month, day, &a, &b);
    n = computeday(a, b, month, day, month_result);
    output(n);

    return 0;
}

void input(int* year, int* month, int* day)
{
    printf("년월일 입력 : ");
    scanf("%d %d %d", year, month, day);

    *month = *month - 1;

    return;
}

int computeyear(int year, int month, int day, int* a, int* b)
{
    for (int i = 1; i < year; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
            ++*a;
        else
            ++ * b;
    }
    return 0;
}

int computemonth(int year, int month, int day, int* a, int* b, int arr1[], int arr2[])
{
    int month_result = 0;

    for (int i = 1; i <= year; i++)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            for (i = 0; i < month; i++)
            {
                month_result += arr1[i];
            }
        }
        else
        {
            for (i = 0; i < month; i++)
            {
                month_result += arr2[i];
            }
        }
    }
    return month_result;
}

int computeday(int a, int b, int month, int day, int month_result)
{
    int n;
    int year_result;

    year_result = (a * 366) + (b * 365);
    n = (year_result + month_result + day) % 7;

    printf("%d\n", year_result);
    printf("%d\n", n);
    return n;
}

void output(int n)
{
    const char* week[] = { "일", "월", "화", "수", "목", "금", "토" };
    printf("%s 요일 입니다.\n", week[n]);
}