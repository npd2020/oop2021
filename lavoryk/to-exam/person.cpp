#include <iostream>

using namespace std;

class Person
{
protected:
  char name[40];

public:
  void getName()
      { cout << "  Enter name: "; cin    >> name;}

  void putName()
     { cout << "  Name: " << name << endl ; }

   virtual void getdata() = 0;      //  pure virtual
   virtual bool   isOutstanding() = 0;  //pure virtual
};

class Student: public Person{
private:
  float gpa;
public:
  void getdata()  {
    Person::getName();
    cout << "  Student's GPA:  "; cin    >> gpa;
  }

  bool isOutstanding(){
    { return ( gpa > 3.5)  ? true :  false; }
  }
};

class Professor: public Person{
private:
  int numPubs;
public:
  void getdata()  {
    Person::getName();
    cout << "  Number of publications:  "; cin    >> numPubs;
  }

  bool isOutstanding(){
    { return (numPubs > 100)  ? true :  false; }
  }

};

int  main() {

  Person* persPtr[100];
  int n   = 0;
  char choice;

  do{
    cout << " Student (s) or professor (p): "  << endl;
    cin >> choice;

    if (choice == 's')
       persPtr[n] = new Student;
    else
       persPtr[n] = new Professor;
   persPtr[n++]->getdata();

   cout << " Would you like to enter one more person (y/n)? " << endl;
   cin   >>   choice;
 } while(choice == 'y');

 for(int j = 0; j < n; j++){
   persPtr[j]->putName();
   if(  persPtr[j]-> isOutstanding())
      cout << "  It is an outstanding person !\n" ;
 }

  return 0;
}
