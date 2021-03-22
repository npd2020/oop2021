#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 20'000'00;

struct Pass {
  int x, y, t;
};

int main() {

  int n, m;
  int x;
  Pass r;

  cin >> n >> m;

  vector<int> distance(n);
  vector<Pass> passes(m);


  for (int i = 0; i < m; i++)
    cin >> passes.at(i).x 
    	  >> passes.at(i).y 
    	  >> passes.at(i).t;

  for (int i = 0; i < n; i++) {

    x = -1;

    for (int j = 0; j < m; j++)

      if (distance[passes[j].y] > distance[passes[j].x] + passes[j].t) {

        distance[passes[j].y] = 
          max (-INF, distance[passes[j].x] + passes[j].t);

        x = passes[j].y;

      }
  }
 
  if (x == -1)
    cout << "not possible" << endl;
  else 
    cout << "possible" << endl;

  return 0;

}