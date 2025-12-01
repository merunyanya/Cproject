// 홍성제
// 사용자가 생각한 숫자를 컴퓨터가 맞히는 게임

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* a, int* b, int* c, int* answer);
void compute(int* a, int* b, int* c, int* answer);
void output(int* a, int* b, int* c, int* answer);

int main()
{
	int answer = 0;
	int a = 0;
	int b = 50;
	int c = 100;

	input(&a, &b, &c, &answer);
	compute(&a, &b, &c, &answer);
	output(&a, &b, &c, &answer);

	return 0;
}

void input(int* a, int* b, int* c, int* answer)
{
	printf("%d<당신의 숫자<%d 이면 1을 입력\n%d<당신의 숫자<%d 이면 2을 입력\n당신의 숫자=%d 이면 3을 입력후 Enter", *a, *b, *b, *c, *b);
	scanf("%d", answer);
}

void compute(int* a, int* b, int* c, int* answer)
{
	while (1)
	{
		if (*answer == 3)
		{
			break;
		}

		else if (*answer == 1)
		{
			*c = *b;
			*b = (*a + *c) / 2;

			if (*b - *a <= 1)
			{
				break;
			}

			else if (*c - *b <= 1)
			{
				break;
			}

			printf("\n%d<당신의 숫자<%d 이면 1을 입력\n%d<당신의 숫자<%d 이면 2를 입력\n당신의 숫자=%d 이면 3을 입력후 Enter", *a, *b, *b, *c, *b);
			scanf("%d", answer);
		}

		else if (*answer == 2)
		{
			*a = *b;
			*b = (*a + *c) / 2;

			if (*b - *a <= 1)
			{
				break;
			}

			else if (*c - *b <= 1)
			{
				break;
			}

			printf("\n%d<당신의 숫자<%d 이면 1을 입력\n%d<당신의 숫자<%d 이면 2를 입력\n당신의 숫자=%d 이면 3을 입력후 Enter", *a, *b, *b, *c, *b);
			scanf("%d", answer);
		}
	}
}

void output(int* a, int* b, int* c, int* answer)
{
	if (*answer == 3)
	{
		printf("\n당신이 생각한 숫자는 %d입니다", *b);
	}

	else if (*answer == 1)
	{
		if (*b - *a <= 1)
		{
			printf("\n당신이 생각한 숫자는 %d입니다", *a + 1);
		}

		else if (*c - *b <= 1)
		{
			printf("\n당신이 생각한 숫자는 %d입니다", *b + 1);
		}
	}

	else if (*answer == 2)
	{
		if (*b - *a <= 1)
		{
			printf("\n당신이 생각한 숫자는 %d입니다", *a + 1);
		}

		else if (*c - *b <= 1)
		{
			printf("\n당신이 생각한 숫자는 %d입니다", *b + 1);
		}
	}
}