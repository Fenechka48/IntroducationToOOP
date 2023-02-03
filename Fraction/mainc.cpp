//Fraction
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
class Fraction
{
	int integer;// 
	int numerator;//
	int denominator;//
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
	//         Methods
	Fraction& to_proper()     // интегрирует целую часть в числитель
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction& to_improper()    //выделяет целую часть из числителя
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
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
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return Fraction * / ;
		Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	)
}

//#define CONSTRACTORS_CHECK
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


	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();
}