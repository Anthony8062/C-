#include <iostream>
#include <string>

using namespace std;

typedef void(*MYFUNC)(int nvalue, void *ctx);

class Admin
{
public:
	MYFUNC m_CallbackFunc;
	void * m_CallbackPtr;

	void Print()
	{
		m_CallbackFunc(10, m_CallbackPtr);
		cout << "Admin member Function" << endl;
	}

	void SetCallbackFunc(void *Func, void *Ptr)
	{
		m_CallbackFunc = (MYFUNC)Func;
		m_CallbackPtr = Ptr;
	}
};

class User
{
private:
	Admin m_Admin;

public:
	void Init()
	{
		m_Admin.SetCallbackFunc(callbackFunc, this);
	}

	static void callbackFunc(int nvalue, void *ctx)
	{
		User *user = (User *)ctx;
		cout << "유저 함수 :: " << nvalue << endl;
		user->Print();
	}

	void Print()
	{
		cout << "User member Function" << endl;
	}

	void Test()
	{
		m_Admin.Print();
	}
};

int main()
{
	User m_User;

	m_User.Init();
	m_User.Test();

	getchar();

	return 0;
}