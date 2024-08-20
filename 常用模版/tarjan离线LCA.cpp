#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
tarjan离线解决LCA
1：先离线所有查询
2：再dfs之后用并查集维护lca问题
    处理儿子，如果有查询的话向上合并那就是root（y） 
*/
const int N = 2e5 + 9;
using PII = pair<int, int>;
int fa[N];
int pre[N];
int vis[N];
int ans[N];
vector<int> g[N];
vector<PII> Q[N];

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y)
{
    int fx = root(x), fy = root(y);
    pre[fx] = fy;
}

void dfs(int x)
{
    vis[x] = 1;

    for (auto v : g[x])
    {
        dfs(v);
    }
    for (auto [y, idx] : Q[x])
    {
        if (!vis[y])
            continue;
        ans[idx] = root(y);
    }
    vis[x] = true;
    merge(x, fa[x]);
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        Q[x].push_back({y, i});
        Q[y].push_back({x, i});
    }
    dfs(1);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';

    //system("pause");
    return 0;
}
