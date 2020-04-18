#include<iostream>
using namespace std;

class SiniveCap
{
public:
	void Take() const { cout << "Äà¹°ÀÌ ³µ´Âµ§´Ù" << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù" << endl; }
};

class SnuffleCpa
{
public:
	void Take() const { cout << "ÄÚ°¡ ¶Õ·Á¿ä" << endl; }
};

class CONTAC600
{
private:
	SiniveCap sin;
	SneezeCap sne;
	SnuffleCpa snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient
{
public:
	void TakeCONTAC(const CONTAC600 &cap) const { cap.Take(); }
};

void main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC(cap);
}