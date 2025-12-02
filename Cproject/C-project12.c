

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void a(int* cc, int* year);
int b(int cc, int year);
void c(int cc, int year, int result);

int main() {
    int cc;
    int year;
    double tax;
    a(&cc, &year);
    int result = b(cc, year);
    c(cc, year, result);
}

void a(int* cc, int* year) {

    printf("배기량(cc)을 입력하세요: ");
    scanf("%d", cc);

    printf("차 구입후 경과년수 입력: ");
    scanf("%d", year);
}

int b(int cc, int year) {

    int rate;
    double discount;

    if (cc <= 800)
    {
        rate = 104;

    }
    else if (cc <= 1000 && cc > 800)
    {
        rate = 130;

    }
    else if (cc <= 1600)
    {
        rate = 182;

    }
    else if (cc <= 2000)
    {
        rate = 260;
    }
    else if (cc <= 2500)
    {
        rate = 286;
    }
    if (year < 3)
    {
        discount = 100;
    }
    else if (year == 3)
    {
        discount = 95;
    }
    else if (year == 4)
    {
        discount = 90;
    }
    else if (year == 5)
    {
        discount = 85;
    }
    else if (year == 6)
    {
        discount = 80;
    }
    else if (year == 7)
    {
        discount = 75;
    }
    else if (year == 8)
    {
        discount = 70;
    }
    else if (year == 9)
    {
        discount = 65;
    }
    else if (year == 10)
    {
        discount = 60;
    }
    else if (year == 11)
    {
        discount = 55;
    }
    else if (year >= 12)
    {
        discount = 50;
    }
    return cc * rate * (discount / 100);


}

void c(int cc, int year, int result)
{
    printf("배기량, %d", cc);
    printf("경과년수, %d", year);
    printf("세금총액, %d", result);

}
