#include <stdio.h>

#define DATA_SIZE 10
//Merge Sort
void __StartMerge(int data[], int p, int q, int r)
{
	int i = p, j = q + 1, k = p;
	int Tempdata[DATA_SIZE];

	while (i <= q && j <= r)
	{
		if (data[i] >= data[j])
			Tempdata[k++] = data[j++];
		else
			Tempdata[k++] = data[i++];
	}

	while (i <= q)
		Tempdata[k++] = data[i++];
	while (j <= r)
		Tempdata[k++] = data[j++];

	int t;
	for (t = p; t <= r; t++)
	{
		data[t] = Tempdata[t];
	}
}

void MergeSort(int data[], int p, int r)
{
	int q;

	if (p < r)
	{
		q = (int)(p + r) / 2.f;

		MergeSort(data, p, q);
		MergeSort(data, q+1, r);
		__StartMerge(data, p, q, r);
	}
}

void PrintSort(int data[], int nSize)
{
	int i;

	for (i = 0; i < nSize; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

int main(void)
{
	int data[DATA_SIZE] = { 2, 20, 40, 60, 41, 22, 8, 7, 27, 50 };

	MergeSort(data, 0, DATA_SIZE-1);
	
	PrintSort(data, DATA_SIZE);

	getchar();

	return 0;
}