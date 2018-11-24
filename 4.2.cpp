# include <iostream>
using namespace std;


class Student
{
private:
	int num;
	char name[5];
	static int total;

public:

	Student() { total++; }
	~Student() { total--; }
	Student(int n, char *p = "wang");
	void static print();
	void Getname();
	int Getnum();
};
int Student::total = 0;
Student::Student(int n, char *p)
{
	n = num;
	total++;
	strcpy_s(name, p);

}

void Student::Getname()
{
	cout << name << endl;

}

int Student::Getnum()
{
	return num;
}

void Student::print()
{
	cout << "the number of the students:" << total << endl;
}

int main()
{
	Student::print();
	Student *p = new Student(13);
	Student::print();
	p->print();
	delete p;
	Student::print();
	Student s[2];
	s[0].print();
	s[2].print();
	system("pause");
	return 0;

}