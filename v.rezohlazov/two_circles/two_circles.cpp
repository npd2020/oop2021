#include "iostream"
#include "math.h"

using namespace std;

double dist_btw_circles(double x1, double y1, double x2, double y2) {
  return std::sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main() {
  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; 

  double dist = dist_btw_circles(x1,y1, x2,y2);

  if (dist == r1+r2) cout << "1\n";
  else if (dist - r1 - r2 < 1.e-10) cout << "2\n";
  else if (dist - r1 - r2 > 1.e-10) cout << "0\n";
  else cout << "-1\n";

  return 0;
}
