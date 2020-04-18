#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vecVal;
	vecVal.push_back(1);
	vecVal.push_back(3);
	vecVal.push_back(5);
	vecVal.push_back(7);
	vecVal.push_back(9);

	//vector<int> vecData(5);
	vector<int> vecData(5, 3);
	
	//vecVal.assign(vecData.begin(), vecData.end());
	vecVal.assign(5, 4);

	vector<int>::iterator itor;
	for (itor = vecVal.begin(); itor != vecVal.end(); ++itor)
	{
		cout << *itor << endl;
	}

	getchar();

	return 1;
}