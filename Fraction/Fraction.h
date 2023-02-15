//Fraction.h
//Fraction
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n-----------------------------------------------\n"
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////class declaration//////////////////////////////////////////////////////
class Fraction;
Fraction operator* (Fraction left, Fraction right);
Fraction operator / (const Fraction& left, const Fraction& right);
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction left, Fraction right);
Fraction& reduce(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator >> (std::istream& is, const Fraction& obj);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//					Constructors:
	Fraction();
	Fraction(double decimal);
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(double integer, double numerator, double denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//        Operators:
	Fraction& operator()(int integer, int numerator, int denominator);

	Fraction& operator = (const Fraction& other);
	Fraction& operator*= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);
	Fraction& operator+= (const Fraction& other);
	Fraction& operator-= (const Fraction& other);
	Fraction& operator ++(int);
	Fraction& operator-- (int);
	//                TYPE-cast operators
	explicit operator int()const;
	explicit operator double()const;

	//         Methods
	Fraction& to_proper();     // интегрирует целую часть в числитель

	Fraction& inverted() const;

	Fraction& to_improper();    //выделяет целую часть из числителя

	Fraction& reduce();

	std::ostream& print(std::ostream& os) const;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////class declaration end//////////////////////////////////////////////////
