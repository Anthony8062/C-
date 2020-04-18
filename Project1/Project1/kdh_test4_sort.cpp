#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int a[] = { 3, 2, 1, 5, 4, 6, 8, 7, 9, 10};
	sort(a, a+10, compare);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	
	getchar();

	return 1;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//class Student
//{
//public:
//	string name;
//	int score;
//
//	Student(string name, int score)
//	{
//		this->name = name;
//		this->score = score;
//	}
//	
//	bool operator < (Student &student)
//	{
//		return this->score < student.score;
//	}
//};
//
//int main(void)
//{
//	Student student[] = {Student("±è µµ Çö", 100), 
//						 Student("±è ¼º ½Ä", 90),
//						 Student("±è ¿ì Çö", 80),
//						 Student("ÀÌ ÇØ Âù", 70),
//						 Student("Á¤ ÇØ ·É", 60)};
//
//	sort(student, student + 5);
//	
//	for (int i = 0; i < 5; i++)
//	{
//		cout << student[i].score << ' ';
//	}
//
//	bool bo = student[1] < student[2];
//
//	cout << bo << endl;
//
//	getchar();
//
//	return 1;
//}