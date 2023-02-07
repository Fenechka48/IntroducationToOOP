//Fraction
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n-----------------------------------------------\n"
class Fraction;
Fraction operator* (Fraction left, Fraction right);
Fraction operator / (const Fraction& left, const Fraction& right);
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction left, Fraction right);
Fraction& reduse (Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator - numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstractor:\t " << this << endl;
	}
	Fraction (double decimal)
	{
		this->integer = decimal;   // сохраним целую часть
		decimal -= integer;          // убираем целую часть 
		this->denominator = 1e+9;
		this->numerator = decimal * denominator;
		reduse();
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constractor:\t\t" << this << endl;
	}
	Fraction(double integer, double numerator, double denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constractor:\t " << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy_constractor:\t " << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t " << this << endl;
	}
	//        Operators:
	Fraction& operator 

	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" <<this<< endl;
		return *this;
	}
	Fraction& operator*= (const Fraction& other)
	{
		return *this = *this *other;
	}
	Fraction& operator /= (const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+= (const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-= (const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator ++(int)
	{
		integer++;
		return *this;
	}
	Fraction& operator-- (int)
	{
		integer--;
		return *this;
	}
	  //                TYPE-cast operators
	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//         Methods
	Fraction& to_proper()     // интегрирует целую часть в числитель
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& inverted() const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& to_improper()    //выделяет целую часть из числителя
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& reduce()
	{
		long long int more, less, rest = 0;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do {
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		long long int GSD = more;   //GCD- Greates Common Division (Наибольшее общее кратное)
		numerator /= GSD;
		denominator /= GSD;
		return *this;
	}

	std::ostream& print (std::ostream& os) const
	{
		if (integer)os<< integer;
		if (numerator)
		{
			if (integer) os << "(";
			os << numerator << "/" << denominator;
			if (integer)os << ")";
		}
		else if (integer == 0) os << 0;
		//cout << endl;
		return os;
	}
};
Fraction operator* (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction result;
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//return Fraction;
	
	// Явно вызываем конструктор и создаем временный безымянный объект,
	// который сразу же возвращается на место вызова:
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()

	).to_proper().reduce();
}
Fraction operator / (const Fraction& left,const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
Fraction operator + (Fraction left, Fraction right)
{
	return Fraction 
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator - (Fraction left, Fraction right)
{
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	left.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	left.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	left.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator >= (const Fraction& left, const Fraction& right)
{
	
	//return left > right || left == right;
	return!(left > right);
}
bool operator <= (Fraction left, Fraction right)
{
	//return left < right || left == right;
	return!(left < right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return obj.print(os);
}
std::istream& operator >> (std::istream& is, const Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);*/
	int number[3] = {};

	const int SIZE = 32;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";

	//is >> buffer;
	is.getline(buffer, SIZE);

	int n = 0;	//счетчик чисел в веденной строке
	//https://legacy.cplusplus.com/reference/cstring/strtok/
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);	//функция atoi(...) ASCII-string to integer преобразует строку в число, если строка является числом, т.е., содержит цифры.
	//https://legacy.cplusplus.com/reference/cstdlib/atoi/

	switch (n)
	{
	case 1:obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:obj(number[0], number[1], number[2]);
	}

	return is;
	
}

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
	Fraction A(2, 3, 4);
	A.print();
	int a = A;
	cout << a << endl;
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