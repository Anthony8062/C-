//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<int, int> mapData;
//	
//	pair<map<int, int>::iterator, bool> pair_map;
//
//	pair_map = mapData.insert(pair<int, int>(0, 50));
//	pair_map = mapData.insert(pair<int, int>(1, 51));
//	pair_map = mapData.insert(pair<int, int>(2, 52));
//	
//	pair_map = mapData.insert(pair<int, int>(2, 53));
//	if (!pair_map.second)
//	{
//		cout << pair_map.first->first << " �ε����� �̹� �����մϴ�." << endl;
//	}
//
//	// [] �����ڸ� ���� insert 
//
//	mapData[2] = 57;
//
//	//1. find
//
//	int nFind = 2;
//
//    map<int, int>::iterator find_itor = mapData.find(nFind);
//	if (find_itor != mapData.end())
//		cout << nFind << "Ű���� " << find_itor->second << " ������ �����մϴ�." << endl;
//	else
//		cout << nFind << "Ű���� �������� �ʽ��ϴ�." << endl;
//
//	//2. upper_bound lower_bound
//	
//	int nBound = 2;
//
//	map<int, int>::iterator bound_lower_itor = mapData.lower_bound(nBound);
//	map<int, int>::iterator bound_uppwer_itor = mapData.upper_bound(nBound);
//
//	if (bound_lower_itor != bound_uppwer_itor)
//		cout << nBound << "Ű ���� " << bound_lower_itor->second << " ������ �����Ѵ�." << endl;
//	else
//		cout << nBound << "Ű ���� �������� �ʴ´�." << endl;
//
//
//	//3. erase
//
//	//mapData.erase(2);
//	//mapData.erase(mapData.begin(), mapData.end());
//
//
//	map<int, int>::iterator map_itor_begin = mapData.begin();
//	map<int, int>::iterator map_itor_end = mapData.end();
//	for (; map_itor_begin != map_itor_end; ++map_itor_begin)
//	{
//		cout << map_itor_begin->second   <<", ";
//	}
//
//
//	getchar();
//
//	return 1;
//}

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> mapData;

	pair<map<int, int>::iterator, bool> pair_map;

	pair_map = mapData.insert(pair<int, int>(1, 3));
	pair_map = mapData.insert(pair<int, int>(2, 5));
	pair_map = mapData.insert(pair<int, int>(3, 7));
	pair_map = mapData.insert(pair<int, int>(4, 9));
	pair_map = mapData.insert(pair<int, int>(5, 11));

	if (!pair_map.second)
		cout << pair_map.first->first << " �ε����� �̹� �����մϴ�." << endl;

	getchar();

	return 1;
}