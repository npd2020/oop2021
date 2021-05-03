#include <iostream>

using namespace std;


class A{

  private:
    int a;


  public:

    A(int sa):
      a(sa){}

    A(){}

  virtual void print_smth(){cout << "I like A: " << a << endl;}

};

class B: public A{
  private:
    int b;


public:

   B(int sb):
      b(sb){}

    B(){}
    void print_smth(){cout << "I like B: " << b << endl;}
};

int main()
{
    B b1(0);
    b1.print_smth();

    A * a1 = &b1;
    a1->print_smth();

    return 0;
}
