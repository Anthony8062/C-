#include <iostream>

using namespace std;

//void Print(T nVal)
//{
//	cout << nVal << endl;
//}
//
//void Print(int nVal)
//{
//	cout << nVal << endl;
//}
//
//class Point
//{
//public:
//	int a = 0, b = 0;
//
//	Point(int nVal, int nVal2)
//	{
//		a = nVal;
//		b = nVal2;
//	}
//};
//
//template <>
//void Print(Point pt)
//{
//	cout << pt.a << endl;
//	cout << pt.b << endl;
//}

class CPoint
{
public:
	int x = 0, y = 0;

	CPoint()
	{
		x = 5;
		y = 7;
	}
};

template <typename T /*= int*/> // 디폴트 템플릿 or 클래스 템플릿 선언시 생략가능
class CBuffer // 클래스를 클래스 템플릿으로
{
private:
	T pt;

public:
	void Print()
	{
		cout << typeid(T).name() << endl;
	}
};

//클래스 템플릿 특수화
template <>
class CBuffer<CPoint> // 단, 기존에 CBuffer 는 클래스 템플릿이 되어있어야 한다. 
{					  // 즉 기존에 클래스 템플릿으로 사용하다가 특수한 경우 다른 클래스를 타입을 설정하여 사용할때 쓰인다.
private:
	CPoint m_pt;
public:
	void Print()
	{
		cout << m_pt.x << endl;
		cout << m_pt.y << endl;
	}
};

int main(void)
{
	//Print("adw"); // 일반 함수 템플릿
	//Print<int> (3);
	//Print<char*> ("char");

	//Point pt(9, 10); // 특수 함수 템플릿
	//Print(pt);

	//CBuffer<int> buffer1; //1. 클래스 템플릿 : 클래스에서 맴버변수의 타입을 T 로 설정 가능
	//buffer1.Print();
	
	//2. 클래스 템플릿 특수화
	CBuffer<CPoint>	t_buf;
	t_buf.Print();
	
	//3. 클래스 템플릿 디폴트 매개변수
	/*CBuffer<>	t_buf3;
	t_buf3.Print();*/

	getchar();

	return 1;
}