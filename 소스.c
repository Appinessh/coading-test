#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int result(int* array, int a, int b,int start, int end)
{
	int mid = (a + b) / 2;
	if (b - a == 1)
	{
		if (start == 1 && end == 1)
		{
			return array[a] > array[b] ? array[a] : array[b];
		}
		else if (start == 1 && end == -1)
		{
			return (array[a] - array[b])>0? (array[a] - array[b]) : 0;
		}
		else if (start == -1 && end == 1)
		{
			return ( - array[a] + array[b])>0? (-array[a] + array[b]) : 0;
		}
		else
		{
			return -array[a] > -array[b] ? -array[a] : -array[b];
		}
	}
	else if (b - a == 0)
	{
		if (start!=end)
		{
			return 0;
		}
		else if(start==1)
		{
			return array[a];
		}
		else
		{
			return -array[a];
		}
	}
	return (result(array, a, mid, start, -1) + result(array, mid + 1, b, 1, end)) > (result(array, a, mid, start, 1) + result(array, mid + 1, b, -1, end)) ? (result(array, a, mid, start, -1) + result(array, mid + 1, b, 1, end)) : (result(array, a, mid, start, 1) + result(array, mid + 1, b, -1, end));
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* height = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &height[i]);
	}
	printf("%d", result(height, 0, n - 1,1,1));
	return 0;
}