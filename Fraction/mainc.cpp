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
		void set_denominator (int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}



   //					Constructors:
		/*Fraction()
		{
			integer = numerator = denominator = 0;
			cout << "DefConstractor:\t " << this << endl;
		}*/

		Fraction(double integer = 0, double numerator = 0, double denominator = 0)
		{
			this->integer = integer;
			this->numerator = numerator;
			this->denominator = denominator; 
			cout << "Constractor:\t " << this << endl;
		}
		~Fraction()
		{
			/*this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;*/
			cout << "Destructor:\t " << this << endl;
		}
   //         Methods
		void print()const
		{
			cout << "number: " << integer << "(" << numerator << "/" << denominator << ")" << endl;
		}
		Fraction& to_proper(Fraction other)    // интегрирует целую часть в числитель
		{

		}
		Fraction& to_improper()                  ////выдел€ет целую часть из числител€
		{

		}

};


void main()
{
	setlocale(LC_ALL, "");
	/*int a;
	Fraction A;
	A.print();
	cout << A.get_integer() << "(" << A.get_numerator() << "/" << A.get_denominator() << ")" << endl;*/

	double integer ;
	double numerator ;
	double denumerator ;
	//cout << "¬ведите целую часть: "; cin >> integer; cout << "ƒробную часть: числитель дроби "; cin >> numerator; cout << "знаменатель"; cin >> denumerator;
	Fraction B=5;
	B.print();
	Fraction C(0,1,2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

}