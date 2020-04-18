#include <iostream>
#include <vector>
//#include <assert.h>
#include <algorithm>

using namespace std;


bool(*pCompare)(int, int);

template <typename T>
bool Compare(T nVal1)
{
	if (nVal1 < 10)
		return true;
	else
		return false;
}

template <typename T, typename T2>
bool Compare2(T nVal1, T2 nVal2)
{
	if (nVal1 < nVal2)
		return true;
	else
		return false;
}

template <typename T, typename T2>
class CCompare
{
public:
	bool operator ()(T nVal1, T2 nVal2)
	{
		if (nVal1 < nVal2)
			return true;
		else
			return false;
	}
};

int main()
{
	int nSize = 5;
	int vecMaxSize = 5;
	bool bCount = false;
	bool bEqual = false;
	int nFind = 3;
	int nCountResult = 0;

	vector<int> vecData;
	vector<int> vecSecond(vecMaxSize, 6);

	vecData.resize(nSize);

	vecData[0] = 1;
	vecData[1] = 2;
	vecData[2] = 3;
	vecData[3] = 4;
	vecData[4] = 5;

	//1. count
	nCountResult = count(vecData.begin(), vecData.end(), nFind);
	cout << nFind << "�� ������" << nCountResult << " �� �Դϴ�." << endl;

	//2. count_if
	bCount = count_if(vecData.begin(), vecData.end(), Compare<int>);
	cout << "count_if �񱳰�� " << bCount << "  �Դϴ�." << endl;

	//3. equal 
	//bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), Compare2<int, int>); // template �Լ� �������
	//pCompare = Compare2;
	//bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), pCompare); // �Լ� ������ ��� ����
	//CCompare<int, int> cmp;
	bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), CCompare<int, int>()); // �Լ� ��ü ��� ����
	cout << "equal �񱳰�� " << bEqual << "  �Դϴ�." << endl;

	getchar();

	return 1;
}