//#include <iostream>
//
//using namespace std;
//
//void Printf()
//{
//	cout << "±âº» printf : " << endl;
//}
//
//struct SPrintf
//{
//	void operator() ()
//	{
//		cout << " °´Ã¼ÀÇ printf : " << endl;
//	}
//};
//
//int main(void) 
//{
//	Printf();
//
//	SPrintf sp;
//	sp();
//
//	getchar();
//
//	return 1;
//}

#include <iostream>

using namespace std;

class Position
{
private:
	int a = 0, b = 0;

public:
	Position()
	{
	}

	Position(int a, int b)
	{
	}

	void operator () ()
	{
		cout << "Position °´Ã¼ printf :" << endl;
	}

	void Printf()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}

	const Position& operator ++ ()
	{
		a++;
		b++;

		return *this;
	}
	const Position operator ++ (int)
	{
		Position pt(a, b);
		++a;
		++b;

		return pt;
	}
};

int main(void)
{
	Position pos1, pos2;
	pos1 = ++pos2;
	pos1.Printf();
	pos1();

	int a = 0, b = 0;
	int aa = 0, bb = 0;

	a = b++;
	aa = ++bb;

	cout << "a : " << a << ",  aa : " << aa << endl;

	getchar();

	return 1;
}