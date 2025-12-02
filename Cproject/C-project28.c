#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* year, int* month, int* day, int* date);
void compute(int* year, int* month, int* day, int date);
void output(int year, int month, int day);

int main()
{
    int year, month, day, date;
    input(&year, &month, &day, &date);
    compute(&year, &month, &day, date);
    output(year, month, day);

    return 0;
}

void input(int* year, int* month, int* day, int* date)
{
    printf("특정일로부터 며칠후 계산 program\n");
    printf("날짜 입력(yyyy.mm.dd) : ");
    scanf("%d.%d.%d", year, month, day);

    printf("며칠 후 입력 : ");
    scanf("%d", date);

    return;
}

void output(int year, int month, int day)
{
    printf("결과 날짜 = %04d.%02d.%02d\n", year, month, day);

    return;
}

void compute(int* year, int* month, int* day, int date)
{
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < date; i++)
    {

        if ((*year % 4 == 0 && *year % 100 != 0) || (*year % 400 == 0))
            days[2] = 29;
        else
            days[2] = 28;

        (*day)++;

        if (*day > days[*month])
        {
            *day = 1;
            (*month)++;

            if (*month > 12)
            {
                *month = 1;
                (*year)++;
            }
        }
    }
    return;
}
