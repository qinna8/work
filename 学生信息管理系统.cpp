# include <iostream>
using namespace std;

# ifndef _STUDENT
# define _STUDENT
# define SIZE 80
class Student
{
private:
	char *name;
	char ID[19];
	char number[10];
	char specia[20];
	int age;
	static int count;
public:
	Student();
	Student(char *na, char *id, char *num, char *spe, int ag);
	Student(const Student &per);
	~Student();
	char* Getname() const;
	char* Getid();
	char* Getnumber();
	char* Getspecia();
	int Getage();
	void Display();
	void Input();
	void Inset();
	void Delete();
	static int Getcount();
};
#endif



//类中函数定义
int Student::count = 0;
Student::Student()
{
	name = NULL;
	age = 0;
}

Student::Student(char* na, char *id, char *num, char *spe, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	strcpy(ID, id);
	strcpy(number, num);
	strcpy(specia, spe);
	age = ag;
	count++;
}

Student::Student(const Student &per)
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	strcpy(ID, per.ID);
	strcpy(number, per.number);
	strcpy(specia, per.specia);
	age = per.age;
	count++;
}

Student::~Student()
{
	cout << "dis" << endl;
	if (name) 
	{
		delete[]name;
	}
	count--;
}

char* Student::Getname()const
{
	return name;
}

char* Student::Getnumber ()
{
	return number;
}

char* Student::Getid()
{
	return ID;
}

char* Student::Getspecia()
{
	return specia;
}

int Student::Getage()
{
	return age;
}

void Student::Display()
{
	cout << "姓  名：" << name << endl;
	cout << "身份证：" << ID << endl;
	cout << "学  号：" << number << endl;
	cout << "专  业：" << specia << endl;
	cout << "年  龄：" << age << endl;
	
}

void Student::Input()
{
	char na[10];
	cout << "输入姓 名：";
	cin >> na;
	if (name)
	{
		delete []name;
	}//如果name指针并不是指向空，那么说明指向上一个人的姓名，所以要delete掉，，，，双重检查
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "输入身份证：";
	cin >> ID;
	cout << "输入年 龄：";
	cin >> age;
	cout << "输入专 业：";
	cin >> specia;
	cout << "输入学 号：";
	cin >> number;
	count++;
}

void Student::Delete()
{
	age = 0;
	count--;
}

void Student::Inset()
{
	if (!age)
	{
		Input();

	}
}

int  Student::Getcount()
{
	return count;

}


//定义对象以及函数，完成相应功能

const int N = 10;
void menu();
void outputstu( Student *array);
void inputstu(Student *array);
int searchstu( Student *array, char *na);
bool insertstu(Student *array);
bool deleltestu(Student *array, char *na);
int main()
{
	Student array[N];
	int choice;
	char na[10];
   
	do
	{
		menu();
		cout << "请输入选项：";
			cin >> choice;
			if (choice > 0 && choice < 6)
				switch (choice)
				{
				case 1:inputstu(array); break;
				case 2:
					cout << "输入要查询的姓名：";
					cin >> na;
					cout << endl;
					int i;
					i = searchstu(array, na);
					if (i == N)
						cout << "查无此人；";
					else
						array[i].Display();
					break;
				case 3:
					outputstu(array); break;
				case 4:
					if (insertstu(array))
					cout<<"成功插入一条记录" << endl;
					   else
					cout << "插入失败！" << endl;
					break;
				case 5:
					cout << "输入要删去信息的人名:";
					cin >> na;
					cout << endl;
					
					i= deleltestu(array, na);
					if (i = 0)
					{
						cout << "删除失败" << endl;
					}
					else
						cout << "成功删除一条记录" << endl;
					break;
				default:break;
				}
	} while (choice);
	system("pause");
	return 0;
}

void menu()
{
	cout << "**********************1.录入信息****************" << endl;
	cout << "**********************2.查询信息****************" << endl;
	cout << "**********************3.浏览信息****************" << endl;
	cout << "**********************4.插入信息****************" << endl;
	cout << "**********************5.删除信息****************" << endl;
	cout << "**********************0.退    出****************" << endl;
}

void outputstu( Student *array)
{
	cout << "学生的总人数=" << Student::Getcount() << endl;
	int i;
	for (i = 0; i < N; i++)
	{
		if (array[i].Getage())
		{
			array[i].Display();
		}
	}
}

void  inputstu(Student *array)
{
	char chm;
	int i = 0;
	do
	{
		if (Student::Getcount()==N)
		{
			cout << "人数已满，无法录入" << endl;
		}
		if (!array[i].Getage())
		{
			
			array[i++].Input();
		}
		cout << "继续输入吗（Y or N）" << endl;
		cin >> chm;
	} while (chm=='Y');
}

int searchstu( Student *array, char *na)

{
	int i, j = N;
	for (i = 0; i < N; i++)
	{
		if (array[i].Getage())
		{
			if (strcmp(array[i].Getname(), na) == 0)
			{
				j = i;
				break;
			}
		}

	}
	return j;
}

bool insertstu(Student *array)
{
	if (Student::Getcount() == N)
	{
		cout << "人数已满，无法插入" << endl;
		return false;
	}
	int i;
	for (i = 0; array[i].Getage(); i++)
	
		array[i].Inset();
	return true;
	

}

bool deleltestu(Student *array, char *na)
{
	if (Student::Getcount() == 0)
	{
		cout << "没有记录，无法删除" << endl;
		return false;
	}
	int i;
	i = searchstu(array, na);
	if (i == N)
	{
		cout << "没有此人，无法删除" << endl;
		return false;
	}
	else
	{
		array[i].Delete();
		return true;
	}
}