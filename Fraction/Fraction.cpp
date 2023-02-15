//Fraction.cpp
#include "Fraction.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////class definition///////////////////////////////////////////////////////
int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator - numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}
//					Constructors:
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefConstractor:\t " << this << endl;
}
Fraction::Fraction(double decimal)
{
	this->integer = decimal;   // сохраним целую часть
	decimal -= integer;          // убираем целую часть 
	this->denominator = 1e+9;
	this->numerator = decimal * denominator;
	reduce();
}
Fraction::Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t " << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constractor:\t\t" << this << endl;
}
Fraction::Fraction(double integer, double numerator, double denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constractor:\t " << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "Copy_constractor:\t " << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t " << this << endl;
}
//        Operators:
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}

Fraction& Fraction::operator = (const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*= (const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator /= (const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator+= (const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-= (const Fraction& other)
{
	return *this = *this - other;
}
Fraction& Fraction::operator ++(int)
{
	integer++;
	return *this;
}
Fraction& Fraction::operator-- (int)
{
	integer--;
	return *this;
}
//                TYPE-cast operators
 Fraction::operator int()const
{
	return Fraction(*this).to_proper().integer;
}

 Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//         Methods
Fraction& Fraction::to_proper()     // интегрирует целую часть в числитель
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::inverted() const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}

Fraction& Fraction::to_improper()    //выделяет целую часть из числителя
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::reduce()
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

std::ostream& Fraction::print(std::ostream& os) const
{
	if (integer)os << integer;
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
Fraction operator / (const Fraction& left, const Fraction& right)
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////class definition end///////////////////////////////////////////////////