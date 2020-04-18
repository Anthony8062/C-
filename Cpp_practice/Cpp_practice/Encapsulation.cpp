#include<iostream>
using namespace std;

class SiniveCap
{
public:
	void Take() const { cout << "�๰�� ���µ���" << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << "��ä�Ⱑ �ܽ��ϴ�" << endl; }
};

class SnuffleCpa
{
public:
	void Take() const { cout << "�ڰ� �շ���" << endl; }
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