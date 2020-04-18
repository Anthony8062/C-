#include <iostream>
#include <Functional>

using namespace std;

template <typename T>
class Less
{
public:
	bool operator () (T nVal1, T nVal2)
	{
		return (nVal1 < nVal2);
	}
};

template <typename T>
class Greater
{
public:
	bool operator () (T nVal1, T nVal2)
	{
		return (nVal1 > nVal2);
	}
};

int main(void)
{
	bool bTrue = false;

	//1. Less ±¸Çö
//	Less<int> tLess;
//	bTrue = tLess(2, 5);

	//2. Greater
	Greater<int> tGreater;
	bTrue = tGreater(5, 2);

	if (bTrue) cout << "True" << endl;
	else cout << "false" << endl;

	getchar();

	return 1;
}