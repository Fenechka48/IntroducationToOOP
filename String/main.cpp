#include <iostream>
using namespace std;

class String
{
	int size;     // ������ ������
	char* str;   // ����� ������ � ������������ ������
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
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
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
	String str1(5);
	str1.print();
}