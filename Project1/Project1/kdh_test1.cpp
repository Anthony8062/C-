//#include <iostream>
//
//using namespace std;
//
//class Position
//{
//private:
//	int x = 0 , y = 0;
//
//public:
//	Position()
//	{
//	}
//
//	Position(int x, int y)
//	{
//	}
//
//	void Printf()
//	{
//		cout << "x = " << x << endl;
//		cout << "y = " << y << endl;
//	}
//
//	const Position& operator++ () // 전위 연산자
//	{
//		x++;
//		y++;
//		return *this;
//	}
//
//	const Position operator++ (int) // 후위 연산자
//	{
//		Position pt(x, y);
//		++x; 
//		++y;
//		return pt;
//	}
//};
//
//int main(void)
//{
//	Position pos1, pos2;
//	pos1 = ++pos2;
//	pos1.Printf();
//
//	pos1++;
//	pos1.Printf();
//
//	getchar();
//
//	return 0;
//}

#include <iostream>

using namespace std;

class Point
{
private:
	int x = 0, y = 0, width = 0, height = 0;

public:
	void Printf()
	{
		cout << "X = " << x << endl;
		cout << "Y = " << y << endl;
		cout << "Width = " << width << endl;
		cout << "Height = " << height << endl;
	}

	const Point* operator ++ ()
	{
		x++;
		y++;
		width++;
		height++;

		return this;
	}

	const Point operator ++ (int)
	{
		Point pt(x, y, width, height);
		++x;
		++y;
		++width;
		++height;

		return pt;
	}

public:
	Point()
	{
	}
	Point(int _x, int _y, int _width, int _height)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
	}
	~Point()
	{
	}
};


int main()
{
	Point pos1;
	Point pos2(3, 3, 3, 3);

	pos1.Printf();
	pos2.Printf();

	pos1++;
	++pos2;

	pos1.Printf();
	pos2.Printf();

	getchar();

	return 1;
}