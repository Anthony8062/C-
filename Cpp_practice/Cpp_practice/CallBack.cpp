#include <windows.h>  
#include <stdio.h>  
#include <conio.h>  
#include <process.h>  

typedef void(*callback_function)(void);

callback_function g_cb = NULL;

/* 외부에서 처리는 작업함수..
* 언제 종료 되는지 , 내가 수행중이던 작업을 끝나고 내 함수를 불러줄지는 알수가 없음
* 내가 등록한 callback 함수를 호출해줄 부분. */
UINT __stdcall extern_work_thread(LPVOID lpVoid)
{
	int num;
	int run = (int)lpVoid;

	while (run)
	{
		printf("작업 중\n");
		num = rand() % 30;
		/* num == 3이 되면 현재 수행중이던 작업이 완료되어
		* 사용자의 요청을 수행할 조건이 되었다!! 라고 가정.
		*/
		if (num == 3)
		{
			/* callback 함수가 호출 된 시점이 되었으나
			* 사용자가 등록을 하였을 때만 호출함
			*/
			printf("호출 준비 중!!\n");
			if (g_cb != NULL)
			{
				/* 사용자가 등록한 callback 함수 호출 */
				g_cb();
				/* callback이 호출 후 초기화 함
				* 이부분은 실제 callback을 호출하는 소스구현에 따라 다름. */
				g_cb = NULL;
			}
			else
			{
				printf("callback 등록이 안되어 있네~!!\n");
			}
		}
		Sleep(100);
	}

	return 0;
}

/* 사용자가 호출 되길 원하는 함수 */
void myCallback(void)
{
	printf("호출됐음!!!\n");
}

/* callback 등록하는 함수 */
void register_callback(callback_function cb)
{
	printf("register_callback 호출 됨!!\n");
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


	/* 나만의 작업이 수행중 */
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