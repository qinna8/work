# include <iostream>
using namespace std;


class Student
{
private:
	int num;
	char name[5];
	
	
public:

	Student() {total++; }
	~Student() { total--;  }
	Student(int n, char *p = "wang");
	static int total;
	void Getname();
	int Getnum();
};
int Student::total=0 ;
Student::Student(int n, char *p)
{
	n = num;
	total++;
	strcpy_s (name, p);

}

void Student::Getname()
{
	cout << name << endl;

}

int Student::Getnum()
{
	return num;
}



int main()
{
	cout << "the number of the students:" << Student::total << endl;
	Studnet *p=new Student(13);
	cout << "the number of the students:" << Student::total << endl;
	cout << "the number of the students:" << p->total << endl;
	delete p;
	cout << "the number of the students:" << Student::total << endl;
	Student s[2];
	cout << "the number of the students:" << s[0].total << endl;
	cout << "the number of the students:" << s[1].total << endl;
	return 0;
}
