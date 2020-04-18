//#include <iostream>
//#include <stack>
//#include <vector>
////#include <algorithm>
//
//using namespace std;
//
//int main(void)
//{
//	vector<int>					vecVal;
//	stack<int, vector<int>>		vecData;
//	vecData.push(5);
//	vecData.push(4);
//	vecData.push(3);
//	vecData.push(2);
//	vecData.push(1);
//
//	int nSize = vecData.size();
//	vector<int>::iterator itor;
//	for (int i = 0; i < nSize; ++i)
//	{
//		cout << "stack" << vecData.top() << endl;
//		vecData.pop();
//	}
//
//	getchar();
//
//	return 1;
//}

#include <iostream>
#include <vector>
#include <stack>
//#include <algorithm>

using namespace std;

int main(void)
{

	vector<int>					vecVal;

	stack<int, vector<int>>		vecData;

	vecData.push(5);
	vecData.push(10);
	vecData.push(15);
	vecData.push(20);
	vecData.push(25);

	int nSize = vecData.size();
	for (int i = 0; i < nSize; ++i)
	{
		cout << "stack " << vecData.top() << endl;
		
		vecData.pop();
	}

	getchar();

	return 1;
}