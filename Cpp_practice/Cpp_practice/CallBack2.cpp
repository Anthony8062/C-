#include <iostream>
#include <string>

using namespace std;

typedef void(*MYFUNC) (int value, void * ctx);

//Admin Class 는 일반적으로 다른 소스파일/헤더파일에 정의가 되어 있을 것이다.
class Admin
{
public:
	MYFUNC m_userfunc;  // User 측에서 콜백함수 등록을 위한 원형 지정
	void * m_userctx;   // User 측에서 콜백함수를 사용할 때, static으로 선언된
						// 콜백함수 내부에서 멤버변수, 멤버함수를 호출하기 위해
						// User Class의 Context를 등록하기 위한 변수

	void print() {
		m_userfunc(10, m_userctx);           // Admin 측에서, 등록된 유저의 콜백함수를 호출
		cout << "관리자 함수 부분" << endl;  // Admin 측에서 정의된 함수 구문
	}
	void RegisterUserFunc(void * func, void * ctx) { // User가 콜백함수를 등록하기 위해 제공되는 함수
		m_userfunc = (MYFUNC)func;                  // User의 콜백함수를 Admin에 등록
		m_userctx = ctx;                            // User의 Context를 저장. 이유는 User 콜백함수 내부에서
													// 멤버함수, 변수에 접근하기 위함이다.
	}
};

class User
{
public:
	Admin m_admin;      // Admin에 의해 제공받은 객체를 선언

	void init() {        // Admin에 User의 콜백함수를 등록하기 위한 초기화 구문
		m_admin.RegisterUserFunc(callbackfunc, this);																// 가장 중요한 핵심 : callbackfunc는 기능의 생겨먹은 형태를 보내는겨
	}																												// 그러니까 callbackfunc는 그냥 기능이야 기능!! 누군가가 얘를
																													// 사용 하겠지 this는 현재 이 클래스 객체를 넘겨준다.
	void print() {       // static으로 선언된 콜백함수에서 올바르게 멤버함수 사용이 가능한지 확인하기 위한 함수
		cout << "멤버함수 사용" << endl;
	}

	static void callbackfunc(int value, void * ctx) {    // Admin에 등록될 콜백함수 정의
		User *thisObj = (User *)ctx;                    // 멤버함수,변수에 접근하기 위한 Context 설정
		cout << "유저 함수 :: " << value << endl;       // Admin에서 사용된 value가 올바르게 출력되는지 확인
		thisObj->print();                               // 멤버함수에 올바르게 접근할 수 있는지 확인
	}

	void test() {        // Admin의 함수 print()를 사용했을 때,
						 // 등록된 콜백함수가 올바르게 작동하는지 확인하기 위한 구문
		m_admin.print();
	}
};

int main(void) {
	User tmp;
	tmp.init();
	tmp.test();
}