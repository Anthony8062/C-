//#include <iostream>
//#include <set>
//#include <Functional> // greater stl ����
//
//using namespace std;
//
//int main()
//{
//	set<int> SetTest1;
//	set<int> SetTest2;
//												//set �� �⺻������ less ������ �Ǹ�, �ߺ��Ǵ� value �� insert �Ǹ� �ߺ� �������� �ʴ´�.
//	pair<set<int>::iterator, bool> pair_Test1; // pair �� iterator �� ����� pair ���ٰ� set �����ֵ��� ����Ű�� �ϰ� pair �� ���̶�� �����ϸ� ��
//
//	pair_Test1 = SetTest1.insert(5);
//	cout << *(pair_Test1.first) << ", ���� ���� : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(7);
//	cout << *(pair_Test1.first) << ", ���� ���� : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(2);
//	cout << *(pair_Test1.first) << ", ���� ���� : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(3);
//	cout << *(pair_Test1.first) << ", ���� ���� : " << pair_Test1.second << endl;
//
//	pair_Test1 = SetTest1.insert(1);
//	cout << *(pair_Test1.first) << ", ���� ���� : " << pair_Test1.second << endl;
//
//	// �ݺ��ڸ� �̿��Ͽ� ��ġ ������ �� insert �ϱ�
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
//	// Ž�� ���
//	//1. count, 2.find
//
//	int CountValue = 5;
//	set<int>::size_type size_t = SetTest1.count(CountValue);
//
//	if (size_t > 0)
//		cout << CountValue << "���� �����մϴ�." << endl;
//	else
//		cout << CountValue << "���� �������� �ʽ��ϴ�." << endl;
//
//	set<int>::iterator itor_set;
//	int FindValue = 7;
//	itor_set = SetTest1.find(FindValue);
//	if (itor_set != SetTest1.end())
//		cout << FindValue << "���� �����մϴ�" << endl;
//	else
//		cout << FindValue << "���� �������� �ʽ��ϴ�." << endl;
//
//
//	//������ ������
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
//	cout << less_comp(3, 4) << endl; // bool Ÿ���� ���Ϲ޴´�.
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
//	//1. �����ڸ� ���� key_comp ���� ���� ������ �ƴ��� ��   //������ ���ǵ� set ���� Ÿ�԰� input ���� ���Ѵ�.
//	int nVal1 = 157, nVal2 = 157;
//	bool bLess = SetLess.key_comp() (nVal1, nVal2);
//	bool bGreater = SetLess.key_comp() (nVal2, nVal1);
//	bool bEqul = false;
//
//	if ((!bLess) && (!bGreater))
//		bEqul = true;
//
//	if (bEqul)
//		cout << nVal1 << "��" << nVal2 << "�� ���� �����ϴ�." << endl;
//	else
//		cout<< nVal1 << "��" << nVal2 << "�� ���� ���� �ʽ��ϴ�." << endl;
//
//	//2. �˻� count, find �� ������� lower_bound, upper_bound ���
//	int nBound = 20;
//	set<int, less<int>>::iterator lower_itor = SetLess.lower_bound(nBound);
//	set<int, less<int>>::iterator uppwer_itor = SetLess.upper_bound(nBound);
//
//	if (lower_itor != uppwer_itor)
//		cout << nBound << "�����մϴ�." << endl;
//	else
//		cout<< nBound << "�������� �ʽ��ϴ�." << endl;
//
//
//	// equal_range  set �������̽� �� ����Ͽ� �� Ž���ϱ�. ���� ������ equal �� �ݺ����� pair �� ���� ��ġ�� �ϰ�������, �ƴϸ� �ٸ���ġ�� ��
//	// ��ȸ�˻��̶�� ��.
//	int nEqual = 30;
//	pair<set<int, less<int>>::iterator, set<int, less<int>>::iterator> less_pair;
//	less_pair = SetLess.equal_range(nEqual);
//
//	cout << *less_pair.first << endl;
//	cout << *less_pair.second << endl;
//
//	if(less_pair.first != less_pair.second)
//		cout << nEqual <<" ���� �����Ѵ�" << endl;
//	else
//		cout << nEqual << " ���� �������� �ʴ´�" << endl;
//
//	for (set<int, less<int>>::iterator itor = SetLess.begin(); itor != SetLess.end(); ++itor)
//	{
//		cout << *itor << endl;
//	}
//
//	//////
//	// multi set �� �̿��� ���
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
//		cout << nfind << "����" << *find_itor << "�� �����Ѵ�."<< endl; //�ݺ��ڵ� ���� 5�� �� ��ġ�� ����Ű�� �ִ�, �� ���� ���� ����Ű���ֳ�.
//	else
//		cout << nfind << "���� �������� �ʴ´�." << endl;
//
//	//2.count
//
//	int nCount = 4;
//	int CountResult = 0;
//	CountResult = msetless.count(nCount);
//
//	cout << nCount <<"�� �� ������" << CountResult <<" �̴�."<< endl;
//
//	//3.lower, upper
//	int nFindBound = 5;
//	multiset<int, less<int>>::iterator lower_itor2 = msetless.lower_bound(nFindBound);
//	multiset<int, less<int>>::iterator upper_itor2 = msetless.upper_bound(nFindBound);
//
//	if (lower_itor2 != upper_itor2)
//		cout << nFindBound << "���� �����Ѵ�." << endl;
//	else
//		cout << nFindBound << "���� �������� �ʴ´�." << endl;
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
//		cout << nEqual << "���� �����Ѵ�. " << endl;
//	else
//		cout << nEqual << "���� �������� �ʴ´�. " << endl;
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
	set<int> SetVal;// �⺻������ Less ��� ������
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
		cout << Detect << "���� �����մϴ�." << endl;
	else
		cout << Detect << "���� �������� �ʽ��ϴ�." << endl;


	//2. find

	set<int>::iterator itor = SetVal.find(Detect);

	if (itor != SetVal.end())
		cout << Detect << "���� �����մϴ�." << endl;
	else
		cout << Detect << "���� �������� �ʽ��ϴ�." << endl;




	getchar();

	return 1;
}