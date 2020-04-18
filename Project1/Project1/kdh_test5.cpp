#include <iostream>

using namespace std;

class Point
{
public:
	void Printf()
	{
		cout << "Point class " << endl;
	}
};

class PointPtr
{
public:
	Point *ptr;

	PointPtr(Point *p)
		:ptr(p)
	{
	}
	~PointPtr()
	{
		delete ptr;
	}

	Point* operator -> ()
	{
		return ptr;
	}

	Point operator * ()
	{
		return *ptr;
	}
	Point* pot()
	{
		return ptr;
	}
};

int main(void)
{
	//Point *pt;						//1
	//PointPtr *ptr = new PointPtr(pt);
	//delete pt;
	//ptr->Printf();

	PointPtr ptr = new Point();

	ptr.pot()->Printf();

	ptr->Printf();
	(*ptr).Printf();

	getchar();

	return 1;
}