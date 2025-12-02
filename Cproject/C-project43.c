#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void input();
void footd(int* foot);
void output(int min, int max, double sum, double stdd, int size);


int main()
{
	input();

	return 0;
}

void input()
{
	int foot[] = { 265,270,290,280,275,270,240,290,280,285,
					275,270,280,280,290,185,190,200,210,250,
					270,260,295,240,230,260,270,280,280,250 };

	footd(foot);
	return;
}

void footd(int* foot)
{

	int max = foot[0];
	int min = foot[0];
	double sum = 0.0;
	double stdd = 0.0;
	int count[301] = { 0 };


	// 최대값, 최소값 계산
	for (int i = 0; i < 30; i++)
	{
		if (foot[i] > max)
		{
			max = foot[i];
		}
		if (foot[i] < min)
		{
			min = foot[i];
		}
	}



	for (int i = 0; i < 30; i++)
	{
		sum += foot[i];
	}
	sum /= 30;



	for (int i = 0; i < 30; i++)
	{
		stdd += pow(foot[i] - sum, 2);
	}
	stdd = sqrt(stdd / 30);



	int size = max - min;


	output(min, max, sum, stdd, size);



	for (int i = 0; i < 30; i++)
	{
		count[foot[i]]++;
	}
	for (int i = 180; i <= 300; i++)
	{
		if (count[i] > 0)
		{
			printf("%3dmm: ", i);

			for (int j = 0; j < count[i]; j++)
			{
				printf("*");
			}

			printf("  (%d)\n", count[i]);
		}
	}


	return;
}

void output(int min, int max, double sum, double stdd, int size)
{

	printf("최소값 : %d\n", min);
	printf("최대값 : %d\n", max);
	printf("평균: %.2lf\n", sum);
	printf("표준편차: %.4lf\n", stdd);
	printf("범위: %d\n\n", size);

	return;
}
