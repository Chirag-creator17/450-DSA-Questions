#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f(i, a, n) for (int i = a; i < n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define se(a) a.begin(), a.end()
bool isCycle(int src, vvi &adj, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto i : adj[src])
    {
        if (i != parent)
        {
            if (visited[i])
                return true;
            if (!visited[i] && isCycle(i, adj, visited, src))
                return true;
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    f(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    f(i, 0, n)
    {
        if (!visited[i] && isCycle(i, adj, visited, -1))
            cycle = true;
    }
    if (cycle)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}