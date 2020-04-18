#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool(*pFunc_if)(int, int);

template <typename T>
bool func_if(T nVal1, T nVal2)
{
	if (nVal1 == nVal2)
		return true;
	else
		return false;
}

template <typename T>
class CFunc_if //�Լ���ü
{
public:
	bool operator ()(T nVal1, T nVal2)
	{
		if (nVal1 == nVal2)
			return true;
		else
			return false;
	}
};


int main()
{
	multimap<int, int> mmapData;

	mmapData.insert(pair<int, int>(0, 50));
	mmapData.insert(pair<int, int>(0, 50));
	mmapData.insert(pair<int, int>(1, 51));
	mmapData.insert(pair<int, int>(2, 52));

	multimap<int, int>::iterator mmap_begin_itor = mmapData.begin();
	multimap<int, int>::iterator mmap_end_itor = mmapData.end();

	//1. lower, upper_bound ���� �˻�
	int nEqual = 0;
	multimap<int, int>::iterator lower_itor = mmapData.lower_bound(nEqual);
	multimap<int, int>::iterator upper_itor = mmapData.upper_bound(nEqual);

	int nCount = 0;
	for (; lower_itor != upper_itor; ++lower_itor)
	{
		nCount++;
	}
	cout << "�� " << nEqual << "�� ������" << nCount << "�Դϴ�." << endl;


	for (; mmap_begin_itor != mmap_end_itor; ++mmap_begin_itor)
	{
		cout << mmap_begin_itor->second << ", ";
	}


	cout << "///////" << endl;

	//2. adjacent_find ����ؼ� �˻��غ���
	//�ߺ��� ���� ��ġ�� �ݺ��ڷ� �����Ѵ�.
	//�Լ��� 3��° �ŰԺ����� ���ǿ� ���� �ٲ��. �⺻ ����Ʈ �ް������� �ߺ��̴�.
	
	vector<int> vecData;

	vecData.push_back(1);
	vecData.push_back(5);
	vecData.push_back(5);
	vecData.push_back(8);
	vecData.push_back(8);
	vecData.push_back(11);

	vector<int>::iterator vec_begin_itor = vecData.begin();
	vector<int>::iterator vec_end_itor = vecData.end();
	for (; vec_begin_itor != vec_end_itor; ++vec_begin_itor)
	{
		cout << *vec_begin_itor << ", ";
	}

	//3. �Լ� ������, �Լ���ü ���
	
	vector<int>::iterator vec_begin_itor2 = vecData.begin();
	vector<int>::iterator vec_end_itor2 = vecData.end();
	vector<int>::iterator vec_itor;

	pFunc_if = func_if<int>;
	CFunc_if<int> Fi;

	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2); //����Ʈ �ް�����
	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, pFunc_if); // �Լ� ������ �ŰԺ���
	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, func_if<int>); // ���ø� �Լ� �ŰԺ���
	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, Fi);// ���ø� Ŭ���� �Լ� operator �ŰԺ���
	vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, CFunc_if<int> ()); // �ӽ� Ŭ���� ���ø� �ŰԺ��� // �Լ���ü


	if (vec_begin_itor2 != vec_end_itor2)
		cout << "�ߺ� �Ǵ� ����" << *vec_itor << endl;
	else
		cout << "�ߺ��Ǵ� ���� ����." << endl;

	

	

	getchar();

	return 1;
}
