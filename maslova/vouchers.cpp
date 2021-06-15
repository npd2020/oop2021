#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include <string>

using namespace std;

int main () {

  int k;
  cin >> k;
  vector <int> positions;
  for (int i=0; i<k; i++) {positions.push_back(i);}
  int day, price;
  vector <int> days = {};
  vector <int> prices = {};

 for (int i=0; i<k; i++){
     cin >> day >> price;
     days.push_back(day);
     prices.push_back(price);
     }

  vector <int> total_sum {};

 do {
        int sum = 0;
  	    for (int i=0; i < k; i++){
  	        if ((days[positions[i]] - i) > 0 ){
  	        sum += (days[positions[i]] - i)*prices[positions[i]];
  	        }
  	    }
  	    total_sum.push_back(sum);
  }  while ( next_permutation(positions.begin(),positions.begin()+k) );

  cout << *max_element(total_sum.begin(), total_sum.end()) << endl;

  return 0;
}
