// 홍성제
// 서기를 간지로 변환

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* year);
void compute(int year, char** gan, char** ji, char** ddi);
void output(int year, char* gan, char* ji, char* ddi);

char* arr1[] = { "갑","을","병","정","무","기","경","신","임","계" };
char* arr2[] = { "자","축","인","묘","진","사","오","미","신","유","술","해" };
char* arr3[] = { "쥐","소","호랑이","토끼","용","뱀","말","양","원숭이","닭","개","돼지" };

int main()
{
    int year = 0;
    char* gan = 0;
    char* ji = 0;
    char* ddi = 0;

    input(&year);
    compute(year, &gan, &ji, &ddi);
    output(year, gan, ji, ddi);

    return 0;
}

void input(int* year)
{
    printf("서기년도를 입력하세요: ");
    scanf("%d", year);
}

void compute(int year, char** gan, char** ji, char** ddi)
{
    int n = year - 4;

    int a = n % 10;
    if (a < 0)
    {
        a += 10;
    }

    int b = n % 12;
    if (b < 0)
    {
        b += 12;
    }

    *gan = arr1[a];
    *ji = arr2[b];
    *ddi = arr3[b];
}

void output(int year, char* gan, char* ji, char* ddi)
{
    printf("%d년의 간지는 %s%s년이고 %s띠의 해입니다.\n", year, gan, ji, ddi);
}