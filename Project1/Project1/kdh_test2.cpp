// 함수 객체(함수자 Functor) : 함수처럼 동작하는 객체

// () 를 연산자 오버로딩을 해야한다


//#include <iostream>
//using namespace std;
//
//void Output(int a, int b)
//{
//	cout << "전역 함수 : " << a << b << endl;
//}
//
//struct FuncObj
//{
//	void operator() (int a, int b)
//	{
//		cout << "함수 객체 !!!"<< a <<", "<< b << endl;
//	}
//};
//
//int main(void)
//{
//	FuncObj funcObj;
//
//	Output(1, 2);
//	funcObj(11, 22); // 멤버함수 호출 funcobj.operator() () 와 같다.
//
//	getchar();
//
//	return 1;
//}

// 함수객체 : 속도가 일반함수보다 빠르다. 일반함수에서 하지 못하는 지원을 받을 수 있다.
// 
#include <iostream>

using namespace std;

struct Object
{
	void operator() (int a, int b)
	{
		cout << "이것은 함수객체이다." << a << endl;
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


