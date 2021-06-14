#include <iostream>
#include <string>

using namespace std;

class ISample // абстрактный класс с чисто виртуальными методами == интерфейс
{
public:
	void virtual DoSomething() = 0;
	void virtual DoSomethingElse() = 0;

};
//////////////////
class Worker
{
public:
	void InteractWith(ISample & sample) // сюда передаю ссылку на любой объект, который реализовывает наш интерфейс
	{ // все классы, которые мы унаследуем от интерфейса семпл, смогут работать с методом интеракт виз 
		cout << "did something" << endl;
		sample.DoSomething();
		cout << "did something else" << endl;
		sample.DoSomethingElse();
	}
};
//////////////////
class Job : public ISample
{
public:
	void DoSomething() override
	{
		cout << "	as Job1" << endl;
	}
	void DoSomethingElse() override
	{
		cout << "	as Job1" << endl;
	}
};
//////////////////
class WrongJob : public ISample
{
public:
	void DoSomething() override
	{
		cout << "	wrong" << endl;
	}
	void DoSomethingElse() override
	{
		cout << "	wrong" << endl;
	}
};

int main()
{	
	Job job1;
	WrongJob job2;
	Worker worker;

	worker.InteractWith(job1);
	cout << endl;
	worker.InteractWith(job2);
}