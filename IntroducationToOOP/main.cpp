//IntroducationToOOP
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;
#define delimiter "\n------------------------------------------\n"
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
	//                          Constructors:
	//Point()
	//{
	//	x = y = 0;
	//	//RAII-Resourse Aqulisation-In Initialisation 
	//	//    (выделение ресурсов -значит инициализация)
	//	cout << "Constructor:\t" << this << endl;
	//}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor: " << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this ->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Distructor:\t" << this << endl;
	}
	//                          Operators:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << " CopyAssignment:\t" << this << endl;
		return *this;
	}
	//                          Methods:
	double distance(const Point& other) const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X= " << x << "\tY= " << y << endl;
	}
};
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRACTOR_CHECK
//# define ASSIGNMENT_CHECK_1
# define ASSIGNMENT_CHECK_2
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
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x (2);
	A.set_y (3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << delimiter << endl;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK
#ifdef CONSTRACTOR_CHECK

	Point A;// Default constracter
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B(2, 3);
	B.print();
	Point C = 4; //Single-Argument constructor
	C.print();
	Point D = C;//copy constractor
	D.print();
	

	Point(const Point & other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstractor: " << this << endl;
	}
	~Point()
	{
		cout << "Distructor:\t" << this << endl;
	}

#endif // CONSTRACTOR_CHECK
#ifdef ASSIGNMENT_CHECK_1


	//CopyAssignment
	Point A(2, 3);
	A.print();
	Point B = A;     //CopyConstructor
	B.print();
	Point C;
	C = B;           //Assignment
	C.print();
#endif // ASSIGNMENT_CHECK_1

	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point(2, 3);
}