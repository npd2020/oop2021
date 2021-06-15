//Calculates amount of digits of integer number
//
#include <iostream>
#include <string>
using namespace std;


int main()
{
    int input_var, length = 1;
    
    //#1                            // debug shown it works faster than #2
    cin >> input_var;               // input number to calculate its length

    string s = to_string(input_var);
    cout << s.length() << endl;

    //#2
/*
    while (input_var >= 10 )
    {
        input_var /= 10;
        length++;
    } 
    cout << length;
*/
}


