# include <iostream>
using namespace std;

# ifndef _Circle
# define _Circle
class Circle
{
private:
	double Radius;
	const double PI;
public:
	Circle(double r = 0) 
	{
		PI(3.1415929);
		Radius = r;
	}
	double Area();
	double Cir();

};
# endif


double Circle::Area()
{
	return PI*Radius*Radius;
}

double Circle::Cir()
{
	return PI * 2 * Radius;
}

int main()
{
	Circle c1(3.5), c2;
	cout << "area of c1=" << c1.Area() << ", cir of c1=" << c1.Cir() << endl;
	cout << "area of c2=" << c2.Area() << ", cir of c2=" << c2.Cir() << endl;
	system("pause");
	return 0;

}