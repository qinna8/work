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



//���к�������
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
	cout << "��  ����" << name << endl;
	cout << "���֤��" << ID << endl;
	cout << "ѧ  �ţ�" << number << endl;
	cout << "ר  ҵ��" << specia << endl;
	cout << "��  �䣺" << age << endl;
	
}

void Student::Input()
{
	char na[10];
	cout << "������ ����";
	cin >> na;
	if (name)
	{
		delete []name;
	}//���nameָ�벢����ָ��գ���ô˵��ָ����һ���˵�����������Ҫdelete����������˫�ؼ��
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "�������֤��";
	cin >> ID;
	cout << "������ �䣺";
	cin >> age;
	cout << "����ר ҵ��";
	cin >> specia;
	cout << "����ѧ �ţ�";
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


//��������Լ������������Ӧ����

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
		cout << "������ѡ�";
			cin >> choice;
			if (choice > 0 && choice < 6)
				switch (choice)
				{
				case 1:inputstu(array); break;
				case 2:
					cout << "����Ҫ��ѯ��������";
					cin >> na;
					cout << endl;
					int i;
					i = searchstu(array, na);
					if (i == N)
						cout << "���޴��ˣ�";
					else
						array[i].Display();
					break;
				case 3:
					outputstu(array); break;
				case 4:
					if (insertstu(array))
					cout<<"�ɹ�����һ����¼" << endl;
					   else
					cout << "����ʧ�ܣ�" << endl;
					break;
				case 5:
					cout << "����Ҫɾȥ��Ϣ������:";
					cin >> na;
					cout << endl;
					
					i= deleltestu(array, na);
					if (i = 0)
					{
						cout << "ɾ��ʧ��" << endl;
					}
					else
						cout << "�ɹ�ɾ��һ����¼" << endl;
					break;
				default:break;
				}
	} while (choice);
	system("pause");
	return 0;
}

void menu()
{
	cout << "**********************1.¼����Ϣ****************" << endl;
	cout << "**********************2.��ѯ��Ϣ****************" << endl;
	cout << "**********************3.�����Ϣ****************" << endl;
	cout << "**********************4.������Ϣ****************" << endl;
	cout << "**********************5.ɾ����Ϣ****************" << endl;
	cout << "**********************0.��    ��****************" << endl;
}

void outputstu( Student *array)
{
	cout << "ѧ����������=" << Student::Getcount() << endl;
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
			cout << "�����������޷�¼��" << endl;
		}
		if (!array[i].Getage())
		{
			
			array[i++].Input();
		}
		cout << "����������Y or N��" << endl;
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
		cout << "�����������޷�����" << endl;
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
		cout << "û�м�¼���޷�ɾ��" << endl;
		return false;
	}
	int i;
	i = searchstu(array, na);
	if (i == N)
	{
		cout << "û�д��ˣ��޷�ɾ��" << endl;
		return false;
	}
	else
	{
		array[i].Delete();
		return true;
	}
}