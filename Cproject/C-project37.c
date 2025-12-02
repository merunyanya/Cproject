#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

char* words[10] = { "태양","국기","처리","책상","사진","대선",
"열쇠","정보","유리","동생" };

char answer[10][64] = { 0 };

void run();
void showwords();
void answerInput();
int answerCompute();
void showanswer(int correct);

int main()
{
    run();
    return 0;
}

void run()
{
    printf("기억력 테스트\n");
    printf("\n화면에 2초 동안 나타나는 10개의 단어를\n");
    printf("순서대로 맞춰야 합니다.\n");
    printf("아무키나 누르면 시작합니다.");
    getch();
    showwords();
    answerInput();
    int correct = answerCompute();
    showanswer(correct);
    return;
}

void showwords()
{
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
    {
        system("cls");
        printf("%d: %s", i + 1, words[i]);
        Sleep(2000);
    }
    system("cls");

    return;
}

void answerInput()
{
    printf("화면에 나타난 단어를 기억하며\n순서대로 입력하고 Enter 합니다.\n");
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
    {
        printf("%d 단어 >", i + 1);
        scanf("%s", answer[i]);
    }

    printf("아무키나 누르면 채점결과가 나타납니다.\n");
    getch();

    return;
}

int answerCompute()
{
    int result = 0;
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
    {
        if (!strcmp(words[i], answer[i]))
        {
            ++result;
        }
    }

    return result;
}

void showanswer(int correct)
{
    printf("%20s %10s", "출제문제", "입력단어\n");
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
    {
        printf("%d \t%s%15s\n", i + 1, words[i], answer[i]);
    }

    printf("총 %d문제 맞았습니다.", correct);

    return;
}
