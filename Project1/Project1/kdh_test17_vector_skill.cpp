#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template <typename T, typename T2>
class CCompare
{
public:
	bool operator () (T nVal1, T2 nVal2 )
	{
		if (nVal1 < nVal2)
			return true;
		else 
			return false;
	}

	string compare_stl(string nVal1, T2 nVal2)
	{
		if (nVal1 && nVal2)
		{
			string str;
			str = "map 값이 모두 정상적으로 존재 합니다";
			return str;
		}
		else
		{
			string str;
			str = "map 값이 정상적으로 존재 하지 않습니다.";
			return str;
		}	
	}
};

int main()
{
	int nSize = 5;
	
	vector<int> vecData;
	vector<int> vecSecond(nSize, 10);
	
	vecData.resize(nSize);
	vecData[0] = 4;
	vecData[1] = 4;
	vecData[2] = 7;
	vecData[3] = 8;
	vecData[4] = 9;

	int nFind = 4;

	bool bEqual = equal(vecData.begin(), vecData.end(), vecSecond.begin(), CCompare<int, int>());

	if (bEqual)
	{
		cout << "vecSecond 요소중 가장 큰 값이 있다." << endl;
	}
	else
		cout << "vecData 요소 중 가장 큰 값이 존재한다." << endl;
		
	vector<int>::iterator vec_itor_begin = vecData.begin();
	vector<int>::iterator vec_itor_end = vecData.end();
	for (; vec_itor_begin != vec_itor_end; ++vec_itor_begin)
	{
		cout << *vec_itor_begin << endl;
	}

	multimap<string, vector<int>> mmapData;
	mmapData.insert(pair<string, vector<int>>("blue", vecData[0]));
	mmapData.insert(pair<string, vector<int>>("white", vecData[1]));
	mmapData.insert(pair<string, vector<int>>("green", vecData[2]));
	mmapData.insert(pair<string, vector<int>>("red", vecData[3]));
	
	bool bCount = count_if(mmapData.begin(), mmapData.end(), CCompare<string, int>());

	if (bCount)
	{
		cout << bCount << "입니다." << endl;
		multimap<string, vector<int>>::iterator mmap_begin_itor = mmapData.begin();
		multimap<string, vector<int>>::iterator mmap_end_itor = mmapData.end();
		for (; mmap_begin_itor != mmap_end_itor; mmap_begin_itor++)
		{
			mmap_begin_itor->first;
			cout << mmap_begin_itor->first << ", " << mmap_begin_itor->second << "의 값이 존재합니다." << endl;
		}
	}
	else
	{
		cout << bCount << "입니다. ㅠㅜ" << endl;
	}

	getchar();

	return 1;
}

//find include <algorithm>
//count
//find_if
//count_if
//equal
//replace
//merge
//generate
//fill_n
// max min  
//iter_swap
//swap_ranges
//transform
//remove
//reverse
//next_permutation
//partition
//random_suffle
//rotate