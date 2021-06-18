#include <iostream>

using namespace std;

class Stack{
protected:

  enum{MAX = 3};  //stack size
  int st[MAX];
  int top;      // last element index

public:
  Stack()       // constructor
  { top = -1; }

  void push(int var)
  {st[++top] = var;}

  int pop()
  {return st [top--]; }

};

class Stack2 :  public Stack{

public:
  void push (int var){
      if(top >= MAX - 1){
         cout  <<   "\nError: stack overflow" <<endl;
      }
  }

  int pop()  {
    if(top < 0){
      cout  <<   "\nError: stack is empty" <<endl;
    }
  }

};

int main(){
  Stack2  s1;

  s1.push(11);
  s1.push(22);
  s1.push(33);

  cout << endl << s1.pop () << endl;
  cout << endl << s1.pop () << endl;
  cout << endl << s1.pop () << endl;
  cout << endl << s1.pop () << endl;
  cout<< endl;
}
