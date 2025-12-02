

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* a, int* b, char* city[]);
void run();
int compute(int arr[][6], int a, int b);
void output(char* city[], int a, int b, int result);

int main()
{
    run();

    return 0;
}

void input(int* a, int* b, char* city[])
{
    for (int i = 0; i < 6; i++)
    {
        printf("%s(%d)", city[i], i);
        if (i == 2)
        {
            printf("\n");
        }
    }
    printf("\n");

    printf("출발지 도시번호 입력하고 Enter>");
    scanf("%d", a);

    printf("도착지 도시번호 입력하고 Enter>");
    scanf("%d", b);

    return;
}

void run()
{
    int a = 0, b = 0;
    int* pa = &a;
    int* pb = &b;

    int arr[6][6] = {
       {0,1700,4200,7500,15200,19300},
       {0,0,3400,6700,13600,17800},
       {0,0,0,4200,11000,15000},
       {0,0,0,0,7800,12100},
       {0,0,0,0,0,4500},
       {0,0,0,0,0,0} };

    char* city[6] = { "서울","수원","천안","대전","대구","부산" };

    input(pa, pb, city);
    int result = compute(arr, a, b);
    output(city, a, b, result);

    return;
}

int compute(int arr[][6], int a, int b)
{
    int result = 0;
    result = arr[a][b];
    return result;
}

void output(char* city[], int a, int b, int result)
{
    printf("%s에서 %s까지 요금: %d", city[a], city[b], result);
    return;
}
