#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int main(void)
//{
//	vector<int> vecValue;
//	vecValue.push_back(2);
//	vecValue.push_back(4);
//	vecValue.push_back(6);
//	vecValue.push_back(8);
//	vecValue.push_back(10);
//
//	vector<int>::iterator itor;
//	for (itor = vecValue.begin(); itor != vecValue.end(); ++itor)
//	{
//		cout << *itor << endl;
//	}
//
//	getchar();
//
//	return 1;
//}

template <typename T, typename FuncT>
void For_each(T begin, T end, FuncT func)
{
	while (begin != end)
	{
		func(*begin);
		++begin;
	}
}

template <typename T>
void PrintT(T nVal)
{
	cout << nVal << endl;
}
	
int main(void)
{
	int ary[] = {2, 4, 6, 8, 10};

	For_each(ary+0, ary+5, PrintT<int>);

	//for_each(ary, ary+5, PrintT<int>);

	getchar();

	return 1;
}