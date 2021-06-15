#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

bool areNeighbors(int n, int m, int i, int j){
    if (n == i){
       if ((j == m - 1) || (j == m + 1)){return true;}
       else return false; }
    else if (m == j){
       if ((i == n - 1) || (i == n + 1)){return true;}
       else return false;}
    else return false;}

void PrintPath(int s_x, int s_y, int v_x, int v_y, vector<vector<pair<int, int>>> pi, vector<vector<char>>& path){
    if ((v_x == s_x) && (v_y == s_y)){
       cout << "Y" << endl;}
    else if (pi[v_x][v_y] == make_pair(-1, -1)) {
       cout << "N" << endl;}
    else {
       PrintPath(s_x, s_y, pi[v_x][v_y].first, pi[v_x][v_y].second, pi, path);
       path[v_x][v_y] = '+';
       }}


int main() {


int N;
cin >> N;
char c;
int arr[N][N] ;
int s_x, s_y;
int f_x, f_y;
for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
        cin >> c;
        if (c == '.') {arr[i][j] = 1;}
        else if (c == 'O') {arr[i][j] = 0;}
        else if (c == '@') {
           arr[i][j] = 2;
           s_x = i;
           s_y = j;}
        else if (c == 'X') {
           arr[i][j] = 1;
           f_x = i;
           f_y = j;}
        }}


int color[N][N];
int d[N][N];
vector<vector<pair<int, int>>> pi(N, vector<pair<int, int>> (N));

for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
       color[i][j] = 0;
       d[i][j] = -1;
       pi[i][j] = make_pair(-1, -1);
    }}

color[s_x][s_y] = 1;
d[s_x][s_y] = 0;

queue<pair<int, int>> Q;
Q.push(make_pair(s_x, s_y));

while (!Q.empty()){
    pair<int, int> u = Q.front();
    //cout << "ux=" << u.first << "uy=" << u.second << endl;
    for (int i=0; i<N; i++){
       for (int j=0; j<N; j++){
            if ( (areNeighbors(i, j, u.first, u.second)==true) && (arr[i][j] == 1) ){
                if(color[i][j] == 0){
                   color[i][j] = 1;
                   d[i][j] = d[u.first][u.second] + 1;
                   pi[i][j] = make_pair(u.first, u.second);
                   Q.push(make_pair(i, j));
                   //cout << "i=" << i << "j=" << j << endl;}
    }
    }}}
    Q.pop();
    color[u.first][u.second] = 2;
    }


vector<vector<char>> path (N, vector<char> (N));
int v_x = f_x;
int v_y = f_y;


for (int i=0; i<N; i++){
   for (int j=0; j<N; j++){
       path[i][j] = '.';}}

PrintPath(s_x, s_y, f_x, f_y, pi, path);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (arr[i][j] == 0 ) path[i][j] = 'O';
            else if  (arr[i][j] == 2 ) path[i][j] ='@';}
            }

if (pi[f_x][f_y] != make_pair(-1, -1)) {
  for (int i=0; i<N; i++){
    if (i != N-1) {for (int j=0; j<N; j++){
          cout << path[i][j] ;}
          cout << endl;}}}

return 0;
}
