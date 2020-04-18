#include <iostream>
#include <string>

using namespace std;

typedef void(*MYFUNC)(int nvalue, void* ctx);

class Aurora
{
public:

	MYFUNC callbackFucn;
	void *callbackPtr;

	void Print()
	{
		callbackFucn(10, callbackPtr);
		cout << "Aurora Print 함수 부분" << endl;
	}

	void SetCallback(void *pFunc, void *pCtx)
	{
		callbackFucn = (MYFUNC)pFunc;
		callbackPtr = pCtx;
	}
};

class Engine
{
public:
	Aurora p_mAurora;
	
	void Init()
	{
		p_mAurora.SetCallback(CallbackFunc, this);
	}

	void Print()
	{
		cout << "Engine Print Func" << endl;
	}

public:

	static void CallbackFunc(int nValue, void *pCtx)
	{
		Engine *Eng = (Engine *)pCtx;
		cout << "Engine Function :: " << nValue << endl;
		Eng->Print();
	}
	
	void test()
	{
		p_mAurora.Print();
	}
};

int main()
{
	Engine Eng;
	Eng.Init();
	Eng.test();
	
	getchar();

	return 0;
}