#include <bits/stdc++.h>
using namespace std;


class Circle{

	private:
		float x;
		float y;
		float r;

public:

	void setX(float xx) {
	 x = xx;
   }

	 void setY(float yy) {
 	  y = yy;
   }

	 void setR(float rr){
	  r = rr;
	 }

   float getX(){
		 return x;
	 }

	 float getY(){
		return y;
	 }

	 float getR(){
		return r;
	 }
};



int circle(float x1, float y1, float x2,
		float y2, float r1, float r2)
{
	float distSq = (x1 - x2) * (x1 - x2) +
				(y1 - y2) * (y1 - y2);
	float radSumSq = (r1 + r2) * (r1 + r2);
	if (distSq == radSumSq)
		return 1;
	else if (distSq > radSumSq)
		return -1;
	else
		return 0;
}


// Driver code
int main()
{

	Circle c1;
  Circle c2;

	float x1 = -10, y1 = 8;
	float x2 = 14, y2 = -24;
	float r1 = 30, r2 = 10;

  c1.setX(x1);
	c1.setY(y1);
	c1.setR(r1);


	c2.setX(x2);
	c2.setY(y2);
	c2.setR(r2);

	float t = circle(c1.getX(), c1.getY(), c2.getX(),
				c2.getY(), c1.getR(), c2.getR());
	if (t == 1)
		cout << "Circle have 2 common points " <<endl;
	else if (t < 0)
		cout << "Circle have 0 common points "<<endl;
	else
		cout << "Circle have 1 common point "<<endl;


	return 0;
}
