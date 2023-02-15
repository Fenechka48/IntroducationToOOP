#include "Fraction.h"


//#define CONSTRACTORS_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS
//#define TYPE_CONVERSIONS_BASICS
//#define HOME_WORK_1
//#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");
	/*int a;
	Fraction A;
	A.print();
	cout << A.get_integer() << "(" << A.get_numerator() << "/" << A.get_denominator() << ")" << endl;*/
#ifdef CONSTRACTORS_CHECK

	Fraction B = 5;
	B.print();
	Fraction C(2, 3);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D;
	E.print();
#endif // CONSTRACTORS_CHECK
#ifdef ARIFMETICAL_OPERATORS_CHECK

	Fraction A(2, 3, 4);
	A.print();
	cout << delimiter << endl;

	Fraction B(3, 4, 5);
	B.print();
	cout << delimiter << endl;

	Fraction C = A * B;
	C.print();
	cout << delimiter << endl;

	Fraction D = A / B;
	D.print();
	cout << delimiter << endl;

	Fraction E = A + B;
	E.print();
	cout << delimiter << endl;

	Fraction M = A - B;
	M.print();
	cout << delimiter << endl;

	A *= B;
	//A = A * B;
	A.print();
	cout << delimiter << endl;

	A /= B;
	A.print();
	cout << delimiter << endl;

	A += B;
	A.print();
	cout << delimiter << endl;

	A -= B;
	A.print();
	cout << delimiter << endl;

	A++;
	A.print();
	cout << delimiter << endl;

	A--;
	A.print();
	cout << delimiter << endl;
#endif // ARIFMETICAL_OPERATORS_CHECK
#ifdef COMPARISON_OPERATORS

	cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
	//cout << (3 == 3) << endl;  
#endif // COMPARISON_OPERATORS
#ifdef TYPE_CONVERSIONS_BASICS

	//(type)value;                           //C-like notation (C-подобная форма записи)
	//type(value);                           // Functional notation (функциональная форма записи)
	//cout << 7. / 2 << endl;
	int a = 2;                               // No conversions
	double b = 3;                            // Conversion from less to more
	int c = b;                               // Conversion from more to less with no data loss
	int d = 4.5;                             // Conversion from more to less with data loss  

	Fraction A = 5;  // Conversion from other class   preformed by SinglArgument constructor
	A.print();

	Fraction B;
	B = 8;           // Conversion from jther class by Assignment operator
#endif // TYPE_CONVERSIONS_BASICS
	/*Fraction A(2, 3, 4);
	A.print();
	int a = A;
	cout << a << endl;*/
#ifdef HOME_WORK_1

	Fraction B(2, 3, 4);
	double b = B;
	cout << b << endl;
#endif // HOME_WORK_1
#ifdef HOME_WORK_2

	Fraction B = 2.75;
	//B.print();
	cout << B << endl;

#endif // HOME_WORK_2

	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
}