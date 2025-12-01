// 최정현
// 두 사람씩 서로의 숫자 카드를 교환

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input();
void assignCards(int* cards, int n);
void swapCards(int* cards, int a, int b);
void output(int* cards, int n);

int main()
{
    input();
    return 0;
}

void input()
{
    int n;

    printf("사람 수를 입력하세요 (짝수만, 예: 10): ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 != 0)
    {
        printf("짝수만 입력 가능합니다.\n");
        return;
    }

    int* cards = (int*)malloc(sizeof(int) * n);
    if (cards == NULL)
    {
        printf("메모리 할당 실패\n");
        return;
    }

    assignCards(cards, n);
    printf("\n[카드 배정 결과]\n");
    output(cards, n);

    // 교환 쌍 정의 (예제처럼 고정된 쌍)
    int pairs[][2] = {
        {0, 7}, {1, 5}, {2, 6}, {3, 8}, {4, 9}
    };
    int pairCount = sizeof(pairs) / sizeof(pairs[0]);

    for (int i = 0; i < pairCount; i++)
    {
        swapCards(cards, pairs[i][0], pairs[i][1]);
        printf("\n사람 %d과 사람 %d이 교환\n", pairs[i][0] + 1, pairs[i][1] + 1);
    }

    printf("\n[교환 후 결과]\n");
    output(cards, n);

    free(cards);
    return;
}

void assignCards(int* cards, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        cards[i] = (rand() % n) + 1;
    }
    return;
}

void swapCards(int* cards, int a, int b)
{
    int temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp;
    return;
}

void output(int* cards, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("사람 %2d: %d\n", i + 1, cards[i]);
    }
    return;
}