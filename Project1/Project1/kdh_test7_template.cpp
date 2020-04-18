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

template <typename T /*= int*/> // ����Ʈ ���ø� or Ŭ���� ���ø� ����� ��������
class CBuffer // Ŭ������ Ŭ���� ���ø�����
{
private:
	T pt;

public:
	void Print()
	{
		cout << typeid(T).name() << endl;
	}
};

//Ŭ���� ���ø� Ư��ȭ
template <>
class CBuffer<CPoint> // ��, ������ CBuffer �� Ŭ���� ���ø��� �Ǿ��־�� �Ѵ�. 
{					  // �� ������ Ŭ���� ���ø����� ����ϴٰ� Ư���� ��� �ٸ� Ŭ������ Ÿ���� �����Ͽ� ����Ҷ� ���δ�.
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
	//Print("adw"); // �Ϲ� �Լ� ���ø�
	//Print<int> (3);
	//Print<char*> ("char");

	//Point pt(9, 10); // Ư�� �Լ� ���ø�
	//Print(pt);

	//CBuffer<int> buffer1; //1. Ŭ���� ���ø� : Ŭ�������� �ɹ������� Ÿ���� T �� ���� ����
	//buffer1.Print();
	
	//2. Ŭ���� ���ø� Ư��ȭ
	CBuffer<CPoint>	t_buf;
	t_buf.Print();
	
	//3. Ŭ���� ���ø� ����Ʈ �Ű�����
	/*CBuffer<>	t_buf3;
	t_buf3.Print();*/

	getchar();

	return 1;
}