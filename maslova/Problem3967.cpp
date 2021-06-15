#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

long count_ropes(vector<int>& v, long len){
    long count = 0;
    for (int i=0; i<v.size(); i++){
        if (v[i] >= len) {count += v[i]/len;}
    }
    return count;}


int main(){

int n, k;
cin >> n >> k;
vector <int> ropes(n);
for (int i=0; i<n; i++){
    int tmp;
    cin >> tmp;
    ropes.push_back(tmp);
}

sort(ropes.rbegin(), ropes.rend());

long init = 0;
for (int i=0; i<n; i++) { init += ropes[i];}
init /= k;

if (init  == 0) {cout << 0;}
else {
long a = count_ropes(ropes, init);
long b;

while (a < k){
    b = (ropes[0]/init) + 1;
    init = ropes[0]/b;
    a = count_ropes(ropes, init);}

cout << init;}

return 0;
}
