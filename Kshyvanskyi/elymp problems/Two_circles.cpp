#include <iostream>
#include <cmath>
using namespace std; //How many points in common two given circles have?

int main () {
	double x1, x2, y1, y2, r1, r2, r;
	
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	r = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)); // Distance between two centres  
	
	if (x1 == x2 && y1 == y2 && r1 == r2) // The same circles
	{  
    	cout << -1 << endl;
  	} 
	
	else if (r > r1 + r2 || r < abs(r1 - r2)) //Too far
	{ 
    cout << 0 << endl; 
	} 
	
	else if (r == r1 + r2 || r == abs(r1 - r2)) // r = r1 + r2
	{ 
    cout << 1 << endl;
	} 
	
	else // Two dots
	{    
    cout << 2 << endl;
	}  
}
