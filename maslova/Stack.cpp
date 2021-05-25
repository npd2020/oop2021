#include<iostream>

using namespace std;

class Stack
{
   public:
   int top_ind;
   int myStack[1000];
   Stack() { top_ind = -1; }
   bool push(int x);
   void pop();
   int top();
   bool isEmpty();
};

   bool Stack::push(int item)
   {
      if (top_ind >= 999) {
      cout << "Stack Overflow";
      return false;
   }
   else {
     myStack[++top_ind] = item;
     return true;
   }
}

  void Stack::pop(){
    if (top_ind < 0)   cout << "Stack Underflow";
    else  top_ind--;
}

  int Stack::top(){
    int item = myStack[top_ind];
    return item;}


  bool Stack::isEmpty(){
    return (top_ind < 0);}



int main(){

 Stack MyStack;
 cout << MyStack.isEmpty() << endl;

 MyStack.push(10);
 cout << MyStack.top() << endl;
 MyStack.pop();

 for (int i=0; i < 20; i++){
    MyStack.push(i);
 }

  cout << MyStack.top() << endl;
  MyStack.pop();
  cout << MyStack.top() << endl;
  cout << MyStack.isEmpty() << endl;


 return 0;
}
