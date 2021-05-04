#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100001;
vector<int> tree [NMAX];
vector<int> killed (NMAX, 0);
vector<bool> used (NMAX, 0);
vector<int> dist (NMAX, 0);
int ans = 0;

void kills(int v, int p)
{
    if (v == p) kills(tree[v][0], v);
    if (tree[v].size() == 2) for (auto to : tree[v]) if (to != p) kills(to, v);
    if (tree[v].size() >= 3) killed[v]++;
    return;
}

void goup(int v, int p)
{
    if (v == p)
    {
        for (auto to : tree[v]) if (dist[to] < dist[v]) goup(to, v);
        killed[v] = 0;
        return;
    }
    if (tree[v].size() == 2) for (auto to : tree[v]) if (to != p) goup(to, v);
    if (tree[v].size() >= 3)
    {
        killed[v]++;
        return;
    }
}


int main()
{
    int n,v; cin>>n;
    if (n <= 5) {cout<<1; return 0;} 
    tree[1].push_back(0);
    vector<int> leaves;
    for (int i = 1; i < n; i++)
    {
        cin>>v;
        tree[v].push_back(i+1);
        tree[i+1].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (tree[i].size() == 1 || (i == 1 && tree[i].size() == 2)) leaves.push_back(i);
    }

    queue<int> q; dist[1] = 0;
    q.push(1); used[1] = true;
    while (!q.empty())
    {
        int qv = q.front(); q.pop();
        used[qv] = 1;
        for (auto to : tree[qv])
        {
            if (!used[to])
            {
                q.push(to);
                dist[to] = dist[qv]+1;
            }
        }
    }

    for (auto l : leaves)
    {
        kills(l, l);
    }

    int maxdist = -1; for (int i = 1; i <= n; i++) maxdist = max(maxdist, dist[i]);
    int wentup = 1;
    while (wentup)
    {
        wentup = 0;
        for (int l = maxdist; l > 0; l--)
        {
            for (int i = 2; i <= n; i++)
            {
                if (killed[i] == 1 && dist[i] == l)
                {
                    goup(i, i);
                    wentup++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) if (killed[i] >= 2) ans++;

    cout<<ans << endl;
    return 0;
}
