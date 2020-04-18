#include <iostream>
#include <string>

using namespace std;

typedef void(*MYFUNC)(int nvalue, void* ctx);


class Admin
{
public:
	MYFUNC	m_CallbackFunc;
	void*	m_CallbackPtr;

	void Print()
	{
		m_CallbackFunc(10, m_CallbackPtr);
		cout << "Admin Print �Լ� �κ�" << endl;
	}

	void SetUseFunction(void *pfunc, void *ctx)
	{
		m_CallbackFunc = (MYFUNC)pfunc;
		m_CallbackPtr = ctx;
	}

};

class User
{
public:
	Admin m_Admin;

	void init()
	{
		m_Admin.SetUseFunction(callbackFunc,this);
	}

	void Print()
	{
		cout << "User Print �Լ� �κ�" << endl;
	}

	static void callbackFunc(int nvalue, void *ctx)
	{
		User *m_User =  (User *)ctx;
		cout << "���� �Լ� :: " << nvalue << endl;       
		m_User->Print();
	}

	void test()
	{
		m_Admin.Print();
	}
};

int main()
{
	User mUser;

	mUser.init();
	mUser.test();

	getchar();

	return 0;
}
