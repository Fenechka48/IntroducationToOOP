#include <iostream>
using namespace std;

class String
{
	int size;     // размер строки
	char* str;   // адрес строки в динамической памяти
public:
	int get_size() const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	//       Constructors:
	
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstractuctor:\t" << this << endl;
	}
	String (const char* str[])
	{
		this->size = strlen(str);
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constractuctor:\t" << this << endl;
	}
	
	String(const String& other)
	{
		this->size = other.size;
		this->str = other.str;
		cout << "Copy_constractor:\t " << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//    Operators
	String& operator = (String& other)
	{
		this->size = other.size;
		this->str = other.str;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//                TYPE-cast operators
	explicit operator char*()const
	{
		return String(*this).str;
	}
	

	//       Methods:
	void print() const
		{
			cout << "Size:\t" << size << endl;
	        cout << "Str:\t" << str << endl;
		}
};

void main()
{
	setlocale(LC_ALL, "");
	/*String str1(5);
	str1.print();*/

	String str=("Hello");
	//cout << str << endl;
	str.print();

	String str1 = ("World");
	str1.print();
	

}