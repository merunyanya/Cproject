#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void input();
void compute(int scores[], int n);
int compare(const void* a, const void* b);


int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	return y - x;
}

int main()
{
	input();

	return 0;
}

void input()
{
	FILE* fp;
	int scores[MAX];
	int n = 0;

	fp = fopen("C:/Users/user/OneDrive/문서/바탕 화면/tjdwjr.txt", "r");
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다. \n");
		return;
	}

	while (fscanf(fp, "%d", &scores[n]) == 1)
	{
		n++;
	}
	fclose(fp);

	qsort(scores, n, sizeof(int), compare);

	compute(scores, n);

	return;
}

void compute(int scores[], int n)
{
	int rank = 1;
	int count = 1;
	printf("등수 \t 점수 \n");
	printf("--------------\n");

	printf("%d \t %d \n", rank, scores[0]);


	for (int i = 1; i < n; i++)
	{
		if (scores[i] == scores[i - 1])
		{
			printf("%d \t %d \n", rank, scores[i]);
		}
		else
		{
			rank = count + 1;
			printf("%d \t %d \n", rank, scores[i]);
		}
		count++;
	}

	return;
}

