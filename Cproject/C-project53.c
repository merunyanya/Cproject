#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void run();
void input(char* answer);
void compute(int* result, char* answer);
void output(int* result, int len);

const char* digits[5][10] =
{
    {"###","  #","###","###","# #","###","###","###","###","###"},
    {"# #","  #","  #","  #","# #","#  ","#  ","  #","# #","# #"},
    {"# #","  #","###","###","###","###","###","  #","###","###"},
    {"# #","  #","#  ","  #","  #","  #","# #","  #","# #","  #"},
    {"###","  #","###","###","  #","###","###","  #","###","###"}
};

int main()
{
    run();
    return 0;
}

void run()
{
    char answer[100] = "";
    int result[100] = { 0 };

    input(answer);
    int len = strlen(answer);
    compute(result, answer);
    output(result, len);

    return;
}

void input(char* answer)
{
    printf("디지털 숫자 출력 프로그램\n");
    printf("0 이상의 정수만 입력합니다.\n\n");
    printf("정수 숫자입력 후 Enter> ");
    scanf("%s", answer);
    return;
}

void compute(int* result, char* answer)
{
    int len = strlen(answer);
    for (int i = 0; i < len; i++)
    {
        result[i] = answer[i] - '0';
    }
    return;
}

void output(int* result, int len)
{
    for (int row = 0; row < 5; row++)
    {
        for (int i = 0; i < len; i++)
        {
            int d = result[i];
            printf("%s ", digits[row][d]);
        }
        printf("\n");
    }
}
