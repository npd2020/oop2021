#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>
#include <chrono>
using namespace std::chrono;
int main() {
int N, S, F, a;
std::cin >> N >> S >> F;
S--;
F--;
int arr[N][N];

for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
        std::cin >> a;
        arr[i][j] = a;}}
auto start = steady_clock::now();
int color[N];
int d[N];
int pi[N];
for (int i=0; i<N; i++){
    color[i] = 0;
    d[i]=0;
    pi[i]=-1;
    }
color[S] = 1;
d[S] = 0;
std::queue<int> Q;
Q.push(S);
while (!Q.empty()){
    int u = Q.front();
    for (int j=0; j<N; j++){
    if (arr[u][j] == 1){
        if(color[j] == 0){
           color[j] = 1;
           d[j] = d[u]+1;
           pi[j] = u;
           Q.push(j);}
    }
    }
    Q.pop();
    color[u] = 2;
    }
auto finish = steady_clock::now();
auto duration = finish - start;
double time = duration_cast<microseconds>(duration).count();
std::cout << "Minimal distance = " << d[F] << std::endl;
std::cout << "Time = " << time << " microseconds" << std::endl;
return 0;
}
