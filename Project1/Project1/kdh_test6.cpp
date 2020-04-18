#include <iostream>

using namespace std;

class Point
{
public:
	void Print()
	{
		cout << "Point °´Ã¼´Ù" << endl;
	}

	/*Point(int a)
	{
	}

	Point(char *sz)
	{
	}
	*/
	operator int()
	{
		return 3;
	}
	operator char* ()
	{
		return "test";
	}
};

int main(void)
{
	/*Point pt(3);

	pt = 3;
	pt = "test";
*/
	//int nVal = pt;

	//char *szVal = pt;

	Point pt;

	int nVal;
	nVal = pt;

	char *szVal;
	szVal = pt;

	cout << nVal << szVal << endl;

	getchar();

	return 1;
}