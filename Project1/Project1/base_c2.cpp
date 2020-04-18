#include <stdio.h>

int main()
{
	int i, j, t, temp, tempValue;
	int size = 8;

	int arr[8] = { 20, 2, 6, 51, 34, 21, 57, 60 };

	for (i = size-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (t = 0; t < 8; t++)
	{
		printf("%3d", arr[t]);
	}

	getchar();

	return 0;
}