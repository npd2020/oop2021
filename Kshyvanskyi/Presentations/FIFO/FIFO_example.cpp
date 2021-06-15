#include<bits/stdc++.h>
using namespace std;
  

void print_queue(queue<int> q)  // print the elements of queue
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
  

int main() 
{ 
    queue<int> q ;
    for (int i = 0; i < 5; i++) // Adds elements {0, 1, 2, 3, 4} to queue 
        q.push(i); 

    int size = q.size(); 
    cout << "Size of queue - " << size << endl;
  
    cout << "Elements of queue - ";    // print contents of the queue
    print_queue(q);
  
  
    int removedele = q.front();    
    q.pop();	//remove the head of queue, in this the oldest element '0' will be removed 
    cout << "Removed element - " << removedele << endl; 
    print_queue(q);
  

    int head = q.front();     // view the head of queue 
    cout << "Head of queue - " << head << endl; 
  
    int size1 = q.size(); 
    cout << "Size of queue - " << size1 << endl;
          
    return 0;
} 
