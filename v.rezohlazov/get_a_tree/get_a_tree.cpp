#include "iostream"
#include "vector"
#include "utility"

using namespace std;

int n;
vector<bool> used[n];

vector<pair<int, int>> edges;
vector<pair<int, int>> removed_edges;
vector<int> connections;

// HAVE TO REWORKE THIS FUNC
void dfs(int node_index) {
  used[node_index] = true;
  for(auto i : connections[node_index]) {
    if(!used[i])
      dfs(i);
  }
}

int main() {
  int m, vert1, vert2;

  cin >> n >> m;
  while(m--) {
    cin >> vert1 >> vert2;
    edges.push_back(make_pair(vert1, vert2));
    connections[vert1].push_back(vert2);
    connections[vert2].push_back(vert1);
  }

  return 0;
}
