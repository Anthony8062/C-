#include<iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple() : num(0){}
	SoSimple(int n) : num(n) {}
};

void main(void)
{
	SoSimple simObj;
	SoSimple *simPtr2 = new SoSimple;
}