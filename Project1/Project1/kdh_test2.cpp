// �Լ� ��ü(�Լ��� Functor) : �Լ�ó�� �����ϴ� ��ü

// () �� ������ �����ε��� �ؾ��Ѵ�


//#include <iostream>
//using namespace std;
//
//void Output(int a, int b)
//{
//	cout << "���� �Լ� : " << a << b << endl;
//}
//
//struct FuncObj
//{
//	void operator() (int a, int b)
//	{
//		cout << "�Լ� ��ü !!!"<< a <<", "<< b << endl;
//	}
//};
//
//int main(void)
//{
//	FuncObj funcObj;
//
//	Output(1, 2);
//	funcObj(11, 22); // ����Լ� ȣ�� funcobj.operator() () �� ����.
//
//	getchar();
//
//	return 1;
//}

// �Լ���ü : �ӵ��� �Ϲ��Լ����� ������. �Ϲ��Լ����� ���� ���ϴ� ������ ���� �� �ִ�.
// 
#include <iostream>

using namespace std;

struct Object
{
	void operator() (int a, int b)
	{
		cout << "�̰��� �Լ���ü�̴�." << a << endl;
	}
};

int main()
{
	//Object ob;
	Object ob2;
	ob2(1, 2);

	getchar();

	return 1;
}


