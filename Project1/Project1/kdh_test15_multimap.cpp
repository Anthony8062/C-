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
class CFunc_if //함수객체
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

	//1. lower, upper_bound 구간 검색
	int nEqual = 0;
	multimap<int, int>::iterator lower_itor = mmapData.lower_bound(nEqual);
	multimap<int, int>::iterator upper_itor = mmapData.upper_bound(nEqual);

	int nCount = 0;
	for (; lower_itor != upper_itor; ++lower_itor)
	{
		nCount++;
	}
	cout << "값 " << nEqual << "의 갯수는" << nCount << "입니다." << endl;


	for (; mmap_begin_itor != mmap_end_itor; ++mmap_begin_itor)
	{
		cout << mmap_begin_itor->second << ", ";
	}


	cout << "///////" << endl;

	//2. adjacent_find 사용해서 검색해보기
	//중복된 곳의 위치를 반복자로 리턴한다.
	//함수의 3번째 매게변수의 조건에 따라 바뀐다. 기본 디폴트 메개변수는 중복이다.
	
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

	//3. 함수 포인터, 함수객체 사용
	
	vector<int>::iterator vec_begin_itor2 = vecData.begin();
	vector<int>::iterator vec_end_itor2 = vecData.end();
	vector<int>::iterator vec_itor;

	pFunc_if = func_if<int>;
	CFunc_if<int> Fi;

	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2); //디폴트 메개변수
	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, pFunc_if); // 함수 포인터 매게변수
	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, func_if<int>); // 템플릿 함수 매게변수
	//vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, Fi);// 템플릿 클래스 함수 operator 매게변수
	vec_itor = adjacent_find(vec_begin_itor2, vec_end_itor2, CFunc_if<int> ()); // 임시 클래스 템플릿 매게변수 // 함수객체


	if (vec_begin_itor2 != vec_end_itor2)
		cout << "중복 되는 원소" << *vec_itor << endl;
	else
		cout << "중복되는 원소 없다." << endl;

	

	

	getchar();

	return 1;
}
