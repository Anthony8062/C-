//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main(void)
//{
//	vector<int> vecVal;
//
//	vecVal.push_back(10);
//	vecVal.push_back(8);
//	vecVal.push_back(6);
//	vecVal.push_back(4);
//	vecVal.push_back(2);
//
//	vector<int>::iterator itor;
//
//	itor = find(vecVal.begin(), vecVal.end(), 8);
//
//	if (itor != vecVal.end()) 
//	{
//		cout <<"find success : "<< *itor << endl; 
//	}
//	else { cout << "find not success " << endl; }
//
//	getchar();
//
//	return 1;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FSort(int nVal, int nVal2)
{
	return (nVal > nVal2);
}

void FPrint(int nVal)
{
	cout << nVal << endl;
}

int main(void)
{
	vector<int> vecVal;

	vecVal.push_back(10);
	vecVal.push_back(49);
	vecVal.push_back(5);
	vecVal.push_back(14);
	vecVal.push_back(1);


	//sort(vecVal.begin(), vecVal.end());
	sort(vecVal.begin(), vecVal.end(), FSort);
	for_each(vecVal.begin(), vecVal.end(), FPrint);

	reverse_iterator<vector<int>::iterator> rBegin(vecVal.end());
	reverse_iterator<vector<int>::iterator> rEnd(vecVal.begin());

	for (; rBegin != rEnd; ++rBegin)
	{
		cout << *rBegin << endl;
	}

	getchar();


	return 1;
}