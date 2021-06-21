#include<iostream>

using namespace std;

template<typename T>
class Stack
{
   public:
   int top_ind;
   T myStack[1000];
   Stack() { top_ind = -1; }
   bool push(T x);
   void pop();
   T top();
   bool isEmpty();
};

  template<typename T>
  bool Stack<T>::push(T item)
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

  template<typename T>
  void Stack<T>::pop(){
    if (top_ind < 0)   cout << "Stack Underflow";
    else  top_ind--;
}
  template<typename T>
  T Stack<T>::top(){
    T item = myStack[top_ind];
    return item;}

  template<typename T>
  bool Stack<T>::isEmpty(){
    return (top_ind < 0);}



int main(){

 Stack <int >MyStack;
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
