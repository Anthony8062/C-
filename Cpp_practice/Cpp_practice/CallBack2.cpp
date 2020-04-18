#include <iostream>
#include <string>

using namespace std;

typedef void(*MYFUNC) (int value, void * ctx);

//Admin Class �� �Ϲ������� �ٸ� �ҽ�����/������Ͽ� ���ǰ� �Ǿ� ���� ���̴�.
class Admin
{
public:
	MYFUNC m_userfunc;  // User ������ �ݹ��Լ� ����� ���� ���� ����
	void * m_userctx;   // User ������ �ݹ��Լ��� ����� ��, static���� �����
						// �ݹ��Լ� ���ο��� �������, ����Լ��� ȣ���ϱ� ����
						// User Class�� Context�� ����ϱ� ���� ����

	void print() {
		m_userfunc(10, m_userctx);           // Admin ������, ��ϵ� ������ �ݹ��Լ��� ȣ��
		cout << "������ �Լ� �κ�" << endl;  // Admin ������ ���ǵ� �Լ� ����
	}
	void RegisterUserFunc(void * func, void * ctx) { // User�� �ݹ��Լ��� ����ϱ� ���� �����Ǵ� �Լ�
		m_userfunc = (MYFUNC)func;                  // User�� �ݹ��Լ��� Admin�� ���
		m_userctx = ctx;                            // User�� Context�� ����. ������ User �ݹ��Լ� ���ο���
													// ����Լ�, ������ �����ϱ� �����̴�.
	}
};

class User
{
public:
	Admin m_admin;      // Admin�� ���� �������� ��ü�� ����

	void init() {        // Admin�� User�� �ݹ��Լ��� ����ϱ� ���� �ʱ�ȭ ����
		m_admin.RegisterUserFunc(callbackfunc, this);																// ���� �߿��� �ٽ� : callbackfunc�� ����� ���ܸ��� ���¸� �����°�
	}																												// �׷��ϱ� callbackfunc�� �׳� ����̾� ���!! �������� �긦
																													// ��� �ϰ��� this�� ���� �� Ŭ���� ��ü�� �Ѱ��ش�.
	void print() {       // static���� ����� �ݹ��Լ����� �ùٸ��� ����Լ� ����� �������� Ȯ���ϱ� ���� �Լ�
		cout << "����Լ� ���" << endl;
	}

	static void callbackfunc(int value, void * ctx) {    // Admin�� ��ϵ� �ݹ��Լ� ����
		User *thisObj = (User *)ctx;                    // ����Լ�,������ �����ϱ� ���� Context ����
		cout << "���� �Լ� :: " << value << endl;       // Admin���� ���� value�� �ùٸ��� ��µǴ��� Ȯ��
		thisObj->print();                               // ����Լ��� �ùٸ��� ������ �� �ִ��� Ȯ��
	}

	void test() {        // Admin�� �Լ� print()�� ������� ��,
						 // ��ϵ� �ݹ��Լ��� �ùٸ��� �۵��ϴ��� Ȯ���ϱ� ���� ����
		m_admin.print();
	}
};

int main(void) {
	User tmp;
	tmp.init();
	tmp.test();
}