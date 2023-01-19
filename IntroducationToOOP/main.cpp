//IntroducationToOOP
#include <iostream>
using namespace std;
class Point // Содавая структуру или класс, мы создаем новый тип данных
	         // классы и структуры еще называют пользовательскими или составными типами данных
{

	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//                          Methods:
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};
//#define STRUCT_POINT

void main()
{
	setlocale (LC_ALL, "");


#ifdef STRUCT_POINT
	Point A;// объявление переменной 'A' типа Point
	        // объявление объекта 'A' структуры Point
	        //создание экземпляра 'A' структуры Point
	        // Объекты часто называют экземплярами класса или структуры
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x (2);
	A.set_y (3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
}