#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 

void intro();
void moveElevator(int from, int to);

int main()
{
    intro();

    srand((unsigned int)time(NULL)); 
    int elevator = (rand() % 16) - 3; 

    while (1)
    {
        int userFloor;
        printf("이용자가 위치한 층을 입력하세요 (종료: 0) Enter: ");
        scanf("%d", &userFloor);

        if (userFloor == 0)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (userFloor < -3 || userFloor > 12)
        {
            printf("잘못된 층입니다. 지하 3층(-3)부터 12층 사이로 입력해주세요.\n");
            continue;
        }

        printf("최초 elevator 위치: %d\n", elevator);
        moveElevator(elevator, userFloor);
        elevator = userFloor;

        int destFloor;
        printf("목적 층을 입력하세요 Enter: ");
        scanf("%d", &destFloor);

        if (destFloor < -3 || destFloor > 12)
        {
            printf("잘못된 층입니다. 다시 입력해주세요.\n");
            continue;
        }

        moveElevator(elevator, destFloor);
        elevator = destFloor;
    }

    return 0;
}

void intro()
{
    printf("이 건물은 지하 3층부터 지상 12층까지 있습니다.\n");
    return;
}

void moveElevator(int from, int to)
{
    if (from == to)
    {
        printf("엘리베이터가 이미 해당 층에 있습니다.\n");
        return;
    }

    int step = (from < to) ? 1 : -1;

    for (int i = from + step; i != to + step; i += step)
    {
        printf("elevator 이동: %d\n", i);
        Sleep(1000); // 1초 지연
    }

    printf("이동이 완료되었습니다.\n");
    return;
}
