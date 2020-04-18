#include <stdio.h>

int partition(int a[], int nBegin, int nEnd)
{
	int L, R, temp, t, pivot;

	L = nBegin;
	R = nEnd;
	pivot = (int)((nBegin + nEnd) / 2.0);

	while (L < R)
	{
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;

		if (L < R)
		{
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
		}

		if (pivot == L)
			pivot = R;
	}

	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;

	for (t = 0; t < 8; t++)
	{
		printf("%3d", a[t]);
	}
	printf("\n");

	return R;
}

void quickSort(int a[], int nBegin, int nEnd)
{
	int p;

	if (nBegin < nEnd)
	{
		p = partition(a, nBegin, nEnd);
		quickSort(a, nBegin, p - 1);
		quickSort(a, p + 1, nEnd);
	}
}

int main()
{
	int arr[8] = { 69, 2, 14, 15, 20, 75, 45, 34 };

	quickSort(arr, 0, 7);

	getchar();

	return 0;
}