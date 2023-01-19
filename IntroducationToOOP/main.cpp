//IntroducationToOOP
#include <iostream>
using namespace std;
class Point // —одава€ структуру или класс, мы создаем новый тип данных
	         // классы и структуры еще называют пользовательскими или составными типами данных
{

	double x;
	double y;
public:

};

void main()
{
	setlocale (LC_ALL, "");
	Point A;// объ€вление переменной 'A' типа Point
	        // объ€вление объекта 'A' структуры Point
	        //создание экземпл€ра 'A' структуры Point
	        // ќбъекты часто называют экземпл€рами класса или структуры
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}