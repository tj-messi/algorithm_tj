#include <bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
mt19937_64 rd(time(0));
vector<ull> hs[N];
queue<int> q[N];
void solve()
{
    int n, k, m = 0;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> cc;
    map<int, int> ys;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cc.push_back(a[i]);
        hs[i].clear();
    }
    sort(cc.begin(), cc.end());
    ys[cc[0]] = ++m;
    for (int i = 1; i < cc.size(); i++)
    {
        if (cc[i] == cc[i - 1])
            continue;
        ys[cc[i]] = ++m;
    }
    vector<int> cnt(m + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = ys[a[i]];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] >= k)
        {
            hs[i].resize(k);
            hs[i][k - 1] = 0;
            for (int j = 0; j < k - 1; j++)
            {
                hs[i][j] = rd();
                hs[i][k - 1] ^= hs[i][j];
            }
        }
        else
        {
            hs[i].resize(cnt[i]);
            for (int j = 0; j < cnt[i]; j++)
            {
                hs[i][j] = rd();
            }
        }
        while (q[i].size())
        {
            q[i].pop();
        }
    }
    vector<int> b(m + 1);
    vector<ull> res(n + 1, 0);
    map<int, int> mp;
    int j = 0, ans = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        q[a[i]].push(i);
        if (q[a[i]].size() > k)
        {
            int ki = q[a[i]].front();
            q[a[i]].pop();
            while (j < ki)
            {
                mp[res[j]]--;
                j++;
            }
        }
        res[i] = res[i - 1] ^ hs[a[i]][b[a[i]] % k];
        b[a[i]]++;
        ans += mp[res[i]];
        mp[res[i]]++;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
