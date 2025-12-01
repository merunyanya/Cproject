//김수경
//트럼프 카드 문제

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct cardtype {
    char* num[13];
} Cardtype;

typedef struct card {
    Cardtype type[4];
} Card;

void run();
void reset();
void showcard(Card card);
void mixdeck(Card card, int* nump, int* typep);
void output(Card card, int* rnum, int* rtype);

int main()
{
    run();
    return 0;
}

void run()
{
    Card card = {
        {
            {"♠A","♠2","♠3","♠4","♠5","♠6","♠7","♠8","♠9","♠10","♠11","♠12","♠13"},
            {"◆A","◆2","◆3","◆4","◆5","◆6","◆7","◆8","◆9","◆10","◆11","◆12","◆13"},
            {"♥A","♥2","♥3","♥4","♥5","♥6","♥7","♥8","♥9","♥10","♥11","♥12","♥13"},
            {"♣A","♣2","♣3","♣4","♣5","♣6","♣7","♣8","♣9","♣10","♣11","♣12","♣13"},
        }
    };

    int randomnum = 0, randomtype = 0;
    int* nump = &randomnum, * typep = &randomtype;

    showcard(card);

    printf("\n선택한 10장의 카드\n");
    //섞은 카드 출력
    for (int i = 0; i < 10; i++)
    {
        mixdeck(card, nump, typep);
        output(card, nump, typep);
    }
    reset();

    return;
}

void reset()
{
    srand(time(NULL));

    return;
}

void showcard(Card card)
{
    printf("섞지않은 상태의 카드\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%s ", card.type[i].num[j]);
        }
        printf("\n");
    }

    return;
}

void mixdeck(Card card, int* nump, int* typep)
{
    *nump = rand() % 12 + 0;
    *typep = rand() % 3 + 0;

    return;
}

void output(Card card, int* rnum, int* rtype)
{
    printf("%s ", card.type[*rtype].num[*rnum]);

    return;
}

