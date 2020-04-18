//#include <iostream>
//#include <set>
//#include <Functional> // greater stl 사용시
//
//using namespace std;
//
//int main()
//{
//	set<int> SetTest1;
//	set<int> SetTest2;
//												//set 은 기본적으로 less 정렬이 되며, 중복되는 value 가 insert 되면 중복 삽입하지 않는다.
//	pair<set<int>::iterator, bool> pair_Test1; // pair 는 iterator 과 비슷함 pair 에다가 set 넣은애들을 가리키게 하고 pair 는 집이라고 생각하면 됨
//
//	pair_Test1 = SetTest1.insert(5);
//	cout << *(pair_Test1.first) << ", 생성 여부 : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(7);
//	cout << *(pair_Test1.first) << ", 생성 여부 : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(2);
//	cout << *(pair_Test1.first) << ", 생성 여부 : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(3);
//	cout << *(pair_Test1.first) << ", 생성 여부 : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(1);
//	cout << *(pair_Test1.first) << ", 생성 여부 : " << pair_Test1.second << endl;
//
//	// 반복자를 이용하여 위치 지정한 후 insert 하기
//	SetTest1.insert(pair_Test1.first, 6); // 1, 2, 3, 5, x, 7
//
//	for (int i = 0; i < 5; i++)  //10 11 12 13 14 15
//	{
//		SetTest2.insert( *(--SetTest1.end()) + i + 3 );
//	}
//	SetTest1.insert(SetTest2.begin(), SetTest2.end());
//
//	for (set<int>::iterator itor = SetTest1.begin(); itor != SetTest1.end(); itor++)
//	{
//		cout << *itor <<" ";
//	}
//	cout << endl;
//
//
//	// 탐색 기능
//	//1. count, 2.find
//
//	int CountValue = 5;
//	set<int>::size_type size_t = SetTest1.count(CountValue);
//
//	if (size_t > 0)
//		cout << CountValue << "값이 존재합니다." << endl;
//	else
//		cout << CountValue << "값이 존재하지 않습니다." << endl;
//
//	set<int>::iterator itor_set;
//	int FindValue = 7;
//	itor_set = SetTest1.find(FindValue);
//	if (itor_set != SetTest1.end())
//		cout << FindValue << "값이 존재합니다" << endl;
//	else
//		cout << FindValue << "값이 존재하지 않습니다." << endl;
//
//
//	//조건자 얻어오기
//	set<int, less<int>>		SetLess;
//	set<int, greater<int>>	SetGreater;
//
//	SetLess.insert(20);
//	SetLess.insert(30);
//	SetLess.insert(40);
//
//	SetGreater.insert(25);
//	SetGreater.insert(35);
//	SetGreater.insert(45);
//
//	set<int, less<int>>::key_compare	less_comp = SetLess.key_comp();
//	cout << less_comp(3, 4) << endl; // bool 타입을 리턴받는다.
//	cout << typeid(less_comp).name() << endl;
//
//	set<int, less<int>>::value_compare	less_val_comp = SetLess.value_comp();
//	cout << less_val_comp(3, 4) << endl; // bool type return
//	cout << typeid(less_val_comp).name() << endl;
//
//	set<int, greater<int>>::key_compare greater_comp = SetGreater.key_comp();
//	cout << greater_comp(3, 4) << endl;
//	cout << typeid(greater_comp).name() << endl;
//
//	cout << "////////////////"<< endl;
//
//	
//
//	//1. 조건자를 통해 key_comp 통한 같은 값인지 아닌지 비교   //기존에 정의된 set 조건 타입과 input 값을 비교한다.
//	int nVal1 = 157, nVal2 = 157;
//	bool bLess = SetLess.key_comp() (nVal1, nVal2);
//	bool bGreater = SetLess.key_comp() (nVal2, nVal1);
//	bool bEqul = false;
//
//	if ((!bLess) && (!bGreater))
//		bEqul = true;
//
//	if (bEqul)
//		cout << nVal1 << "과" << nVal2 << "는 서로 같습니다." << endl;
//	else
//		cout<< nVal1 << "과" << nVal2 << "는 서로 같지 않습니다." << endl;
//
//	//2. 검색 count, find 외 방법으로 lower_bound, upper_bound 방법
//	int nBound = 20;
//	set<int, less<int>>::iterator lower_itor = SetLess.lower_bound(nBound);
//	set<int, less<int>>::iterator uppwer_itor = SetLess.upper_bound(nBound);
//
//	if (lower_itor != uppwer_itor)
//		cout << nBound << "존재합니다." << endl;
//	else
//		cout<< nBound << "존재하지 않습니다." << endl;
//
//
//	// equal_range  set 인터페이스 를 사용하여 값 탐색하기. 값이 없으면 equal 의 반복자인 pair 는 같은 위치를 하고있으나, 아니면 다른위치가 됨
//	// 우회검색이라고 함.
//	int nEqual = 30;
//	pair<set<int, less<int>>::iterator, set<int, less<int>>::iterator> less_pair;
//	less_pair = SetLess.equal_range(nEqual);
//
//	cout << *less_pair.first << endl;
//	cout << *less_pair.second << endl;
//
//	if(less_pair.first != less_pair.second)
//		cout << nEqual <<" 값이 존재한다" << endl;
//	else
//		cout << nEqual << " 값이 존재하지 않는다" << endl;
//
//	for (set<int, less<int>>::iterator itor = SetLess.begin(); itor != SetLess.end(); ++itor)
//	{
//		cout << *itor << endl;
//	}
//
//	//////
//	// multi set 을 이용한 방법
//
//	multiset<int, less<int>> msetless;
//
//	msetless.insert(4);
//	msetless.insert(5);
//	msetless.insert(4);
//	msetless.insert(7);
//
//	//1.find
//	int nfind = 4;
//
//	multiset<int, less<int>>::iterator find_itor = msetless.find(nfind);
//	if (find_itor != msetless.end())
//		cout << nfind << "값이" << *find_itor << "에 존재한다."<< endl; //반복자도 같은 5의 전 위치를 가리키고 있다, 즉 같은 값을 가리키고있네.
//	else
//		cout << nfind << "값이 존재하지 않는다." << endl;
//
//	//2.count
//
//	int nCount = 4;
//	int CountResult = 0;
//	CountResult = msetless.count(nCount);
//
//	cout << nCount <<"의 값 갯수는" << CountResult <<" 이다."<< endl;
//
//	//3.lower, upper
//	int nFindBound = 5;
//	multiset<int, less<int>>::iterator lower_itor2 = msetless.lower_bound(nFindBound);
//	multiset<int, less<int>>::iterator upper_itor2 = msetless.upper_bound(nFindBound);
//
//	if (lower_itor2 != upper_itor2)
//		cout << nFindBound << "값은 존재한다." << endl;
//	else
//		cout << nFindBound << "값은 존재하지 않는다." << endl;
//
//	//4.equal
//	int nEqual2 = 5;
//	
//    pair<multiset<int, less<int>>::iterator, multiset<int, less<int>>::iterator> pair_mset = msetless.equal_range(nEqual2);
//
//	cout << *pair_mset.first << endl;
//	cout << *pair_mset.second << endl;
//
//	if (pair_mset.first != pair_mset.second)
//		cout << nEqual << "값이 존재한다. " << endl;
//	else
//		cout << nEqual << "값이 존재하지 않는다. " << endl;
//
//	/////
//	multiset<int, less<int>>::iterator mset_itor_begin = msetless.begin();
//	multiset<int, less<int>>::iterator mset_itor_end = msetless.end();
//	cout << " //// "<<endl;
//	for (; mset_itor_begin != mset_itor_end; ++mset_itor_begin)
//	{
//		cout << *mset_itor_begin;
//	}
//	cout << endl;
//
//
//	getchar();
//
//	return 1;
//}

#include <iostream>
#include <set>
#include <Functional>

using namespace std;

int main()
{
	set<int> SetVal;// 기본적으로 Less 기능 동작함
	set<int> SetData;

	pair<set<int>::iterator, bool> Pair_Set;

	Pair_Set = SetVal.insert(5);
	Pair_Set = SetVal.insert(7);
	Pair_Set = SetVal.insert(9);
	Pair_Set = SetVal.insert(1);
	Pair_Set = SetVal.insert(3);
	
	set<int>::iterator itor_begin = SetVal.begin();
	set<int>::iterator itor_end = SetVal.end();

	for (itor_begin; itor_begin != itor_end; ++itor_begin)
	{
		cout << *itor_begin << endl;
	}
	////////////////////////////

	//1. count
	int Detect = 5;
	set<int>::size_type sizetype = SetVal.count(Detect);

	if (sizetype > 0)
		cout << Detect << "값이 존재합니다." << endl;
	else
		cout << Detect << "값이 존재하지 않습니다." << endl;


	//2. find

	set<int>::iterator itor = SetVal.find(Detect);

	if (itor != SetVal.end())
		cout << Detect << "값이 존재합니다." << endl;
	else
		cout << Detect << "값이 존재하지 않습니다." << endl;




	getchar();

	return 1;
}