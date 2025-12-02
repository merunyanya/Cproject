#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

typedef struct menu {
    char name[20];
    int price;
} Menu;

void run();
void show(Menu menu[], int coin);
int putcoin();
int enternum();
int outputresult(Menu menu[], int num, int coin);
void outputchange(int change);

int main()
{
    run();
    return 0;
}

void run()
{
    int coin = 0;
    int num = 0;

    Menu menu[4] = {
        {"커피", 330},
        {"콜라", 400},
        {"주스", 600},
        {"취소", 0}
    };

    while (1)
    {
        show(menu, coin);
        coin += putcoin();
        show(menu, coin);

        num = enternum();

        if (num == 4)
        {
            outputchange(coin);
            break;
        }

        int price = menu[num - 1].price;

        if (coin < price)
        {
            continue;
        }

        printf("\n%s를 받으세요.\n", menu[num - 1].name);

        int change = coin - price;
        outputchange(change);

        break;
    }
}

void show(Menu menu[], int coin)
{
    system("cls");

    for (int i = 0; i < 3; i++)
    {
        printf("%d: %s(%d원)\t%s\n",
            i + 1,
            menu[i].name,
            menu[i].price,
            (coin < menu[i].price) ? "판매불가" : "판매가능");
    }
    printf("4: %s\n", menu[3].name);

    printf("\n현재 금액: %d원\n", coin);
}

int putcoin()
{
    int coin = 0;
    printf("\n금액을 입력하고 Enter: ");
    scanf("%d", &coin);

    return coin;
}

int enternum()
{
    int num = 0;
    printf("\n번호를 선택하고 Enter: ");
    scanf("%d", &num);

    return num;
}

void outputchange(int change)
{
    if (change <= 0)
    {
        printf("\n거스름돈이 없습니다.\n");
        system("pause");
        return;
    }

    printf("\n거스름돈 총액: %d원\n", change);

    int c500 = change / 500; change %= 500;
    int c100 = change / 100; change %= 100;
    int c50 = change / 50;  change %= 50;
    int c10 = change / 10;  change %= 10;

    printf("500원: %d개\n", c500);
    printf("100원: %d개\n", c100);
    printf("50원: %d개\n", c50);
    printf("10원: %d개\n", c10);

    system("pause");
}

