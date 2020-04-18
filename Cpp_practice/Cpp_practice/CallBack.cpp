#include <windows.h>  
#include <stdio.h>  
#include <conio.h>  
#include <process.h>  

typedef void(*callback_function)(void);

callback_function g_cb = NULL;

/* �ܺο��� ó���� �۾��Լ�..
* ���� ���� �Ǵ��� , ���� �������̴� �۾��� ������ �� �Լ��� �ҷ������� �˼��� ����
* ���� ����� callback �Լ��� ȣ������ �κ�. */
UINT __stdcall extern_work_thread(LPVOID lpVoid)
{
	int num;
	int run = (int)lpVoid;

	while (run)
	{
		printf("�۾� ��\n");
		num = rand() % 30;
		/* num == 3�� �Ǹ� ���� �������̴� �۾��� �Ϸ�Ǿ�
		* ������� ��û�� ������ ������ �Ǿ���!! ��� ����.
		*/
		if (num == 3)
		{
			/* callback �Լ��� ȣ�� �� ������ �Ǿ�����
			* ����ڰ� ����� �Ͽ��� ���� ȣ����
			*/
			printf("ȣ�� �غ� ��!!\n");
			if (g_cb != NULL)
			{
				/* ����ڰ� ����� callback �Լ� ȣ�� */
				g_cb();
				/* callback�� ȣ�� �� �ʱ�ȭ ��
				* �̺κ��� ���� callback�� ȣ���ϴ� �ҽ������� ���� �ٸ�. */
				g_cb = NULL;
			}
			else
			{
				printf("callback ����� �ȵǾ� �ֳ�~!!\n");
			}
		}
		Sleep(100);
	}

	return 0;
}

/* ����ڰ� ȣ�� �Ǳ� ���ϴ� �Լ� */
void myCallback(void)
{
	printf("ȣ�����!!!\n");
}

/* callback ����ϴ� �Լ� */
void register_callback(callback_function cb)
{
	printf("register_callback ȣ�� ��!!\n");
	if (cb != NULL)
	{
		g_cb = cb;
	}
}

int main(void)
{
	int ch;
	HANDLE hThread = NULL;
	unsigned int id;
	int bThreadPw = 1;
	unsigned int count;

	hThread = (HANDLE)_beginthreadex(0, 0, extern_work_thread, &bThreadPw, 0, &id);


	/* ������ �۾��� ������ */
	while (1)
	{
		ch = _getch();
		if (ch == '1')
		{
			register_callback(myCallback);
		}
		else
			break;
	}

	bThreadPw = 0;
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	hThread = NULL;
	return 0;
}