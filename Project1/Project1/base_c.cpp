#include <stdio.h>

//select sort
int main()
{
	int arr[8] = {2, 50, 91, 24, 94, 64, 35, 23};

	int i, j, t, temp, tempValue;

	int size = 8;

	for (i = 0; i < 7; i++)
	{
		tempValue = i;

		for (j = i+1; j <8; j++)
		{
			if (arr[j] < arr[tempValue])
				tempValue = j;
		}

		temp = arr[i];
		arr[i] = arr[tempValue];
		arr[tempValue] = temp;
	}

	for (t = 0; t < 8; t++)
	{
		printf("%3d", arr[t]);
	}

	getchar();

	return 0;
}