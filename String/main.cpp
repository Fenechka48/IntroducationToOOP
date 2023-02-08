#include <iostream>
using namespace std;
#define delimiter "\n-----------------------------------------------\n"
class String;
String operator +=(const String& left, const String& right);


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
	char* get_str() 
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
	String (const char* str)
	{
		this->size = strlen(str)+1;        //функция возвращает размер в символах, но в классе хранится размер в байтах и терминирующего символа
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "1ArgConstractuctor:\t" << this << endl;
	}
	
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "Copy_constractor:\t " << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//    Operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator +=(const String& other)
	{
		return *this = *this +other;
	}
	char& operator[](int i)
	{
		return str[i];
	}
	char& operator[](int i) const
	{
		return str[i];
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

std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+ (const String& left, const String& right)
{
	String cat (left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right.get_str()[i];
	return cat;

}

void main()
{
	setlocale(LC_ALL, "");
	/*String str1(5);
	str1.print();*/

	String str=("Hello");
	str = str;
	cout << str << endl;

	str.print();
	cout << delimiter << endl;

	String str1 = ("World");
	str1.print();
	cout << delimiter << endl;

	str += str1;
	cout << str << endl;
	/*String str3;
	str3 = str + str1;
	cout << str3 << endl;
	cout << delimiter << endl;

	str1 = str3;
	cout << str1 << endl;*/
}