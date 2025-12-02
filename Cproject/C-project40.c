#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input();
void simulate(int n);
void output(int front, int back, int total);

int main()
{
    input();
    return 0;
}

void input()
{
    int n;

    printf("동전던지기 모의실험\n");
    printf("시행횟수 입력(최대 1,000,000번): ");
    scanf("%d", &n);

    if (n < 1 || n > 1000000)
    {
        printf("잘못된 입력입니다. 1~1,000,000 사이의 값을 입력해주세요.\n");
        return;
    }

    simulate(n);
    return;
}

void simulate(int n)
{
    int front = 0;
    int back = 0;

    srand((unsigned int)time(NULL)); // 난수 초기화

    for (int i = 0; i < n; i++)
    {
        int toss = rand();
        if (toss % 2 == 1)
            front++;
        else
            back++;
    }

    output(front, back, n);
    return;
}

void output(int front, int back, int total)
{
    double prob_front = (double)front / total;
    double prob_back = (double)back / total;

    printf("시행횟수: %d\n", total);
    printf("앞면: %d (Prob: %.6lf)\n", front, prob_front);
    printf("뒷면: %d (Prob: %.6lf)\n", back, prob_back);

    return;
}
