#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SampleClass
{
protected:
	string m_name;
	T m_a;
	T m_b;

public:
	SampleClass() :
		m_name("0"), m_a(0), m_b(0) {}

	SampleClass(string name, T a, T b) :
		m_name(name), m_a(a), m_b(b) {}

	string  getName() { return m_name; }
	T getA() { return m_a; }
	T getB() { return m_b; }

	void setName(string name) { m_name = name; }
	void setA(T a) { m_a = a; }
	void setB(T b) { m_b = b; }

	void MultiplyAsName()
	{
		m_name = to_string(m_a) + " * " + to_string(m_b) + " = " + to_string(m_a*m_b);
	}
};

int main()
{
	
	cout << SampleClass<int>().getName() << endl;
	cout << SampleClass<int>().getA() << endl;
	cout << SampleClass<int>().getB() << endl << endl;

	SampleClass<int> xd("name", 4, 5);
	cout << xd.getName() << endl;
	cout << xd.getA() << endl;
	cout << xd.getB() << endl << endl;

	xd.setName("to multiply:");
	xd.setB(13);
	xd.setA(2);

	cout << xd.getName() << endl;
	cout << xd.getA() << endl;
	cout << xd.getB() << endl << endl;

	xd.MultiplyAsName();

	cout << xd.getName() << endl;


}