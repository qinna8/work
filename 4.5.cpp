# include <iostream>
# include <string>
using namespace std;

class person
{
private:
	int age;
	char *name;
public:
	person(int n = 1, char *na = "Zhuli");
	~person();
	void print();
	void print()const;
	void modifyage();
};

person::person(int n, char *na)
{
	age = n;
	name = new char[strlen(na) + 1];
	strcpy_s(name, na);
}

person::~person()
{
	delete[]name;
}

void person::print()
{
	cout << "age:" << age << "  name:" << name << endl;
	cout << "this is general print" << endl;
}

void person::print()const
{
	cout << "age:" << age << "  name:" << name << endl;
	cout << "this is const print" << endl;
}

void person::modifyage()
{
	age++;
}

int main()
{
	const person p1(17, "wu");
	cout << "output const object p1" << endl;
	p1.print();
	person p2(18, "zhang ");
	cout << "output general object p2 " << endl;
	p2.modifyage();
	p2. print();
	system("pause");
	return 0;
}