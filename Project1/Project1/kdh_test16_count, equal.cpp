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
	cout << nFind << "의 갯수는" << nCountResult << " 개 입니다." << endl;

	//2. count_if
	bCount = count_if(vecData.begin(), vecData.end(), Compare<int>);
	cout << "count_if 비교결과 " << bCount << "  입니다." << endl;

	//3. equal 
	//bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), Compare2<int, int>); // template 함수 사용조건
	//pCompare = Compare2;
	//bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), pCompare); // 함수 포인터 사용 조건
	//CCompare<int, int> cmp;
	bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), CCompare<int, int>()); // 함수 객체 사용 조건
	cout << "equal 비교결과 " << bEqual << "  입니다." << endl;

	getchar();

	return 1;
}