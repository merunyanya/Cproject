// 정재범
// 실수형 숫자의 카운트

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input(char* a);
void compute(char* num[], int* cnt, char* a);
void output(char* num[], int* cnt);

int main()
{
    char a[20];
    char* num[10] = { "0","1","2","3","4","5","6","7","8","9" };
    int cnt[10] = { 0 };

    input(a);
    compute(num, cnt, a);
    output(num, cnt);

    return 0;
}

void input(char* a)
{
    printf("실수 숫자의 카운트\n");
    printf("실수 입력후 enter하세요.\n");
    printf("정수, 실수부분은 9자리를 초과 할수 없음\n");
    printf("입력: ");
    scanf("%s", a);
}

void compute(char* num[], int* cnt, char* a)
{
    int len = strlen(a);

    for (int j = 0; j < len; j++)
    {
        if (a[j] >= '0' && a[j] <= '9')
        {
            int digit = a[j] - '0';   // 문자 → 숫자 인덱스
            cnt[digit]++;
        }
    }
}

void output(char* num[], int* cnt)
{
    printf("num\tcnt\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%s\t%d\n", num[i], cnt[i]);
    }
}
