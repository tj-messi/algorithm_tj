#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

int lowbit(int x) 
{
    return x & -x;
}


void solve()
{
	string s;
    cin >> s; 
    int n = s.size();
    s = " " + s;
    vector<array<array<int, 2>, 2>> tr(2e5 + 1);
    auto add = [&](int x, int k, int op) {
        for ( ; x < tr.size(); x += lowbit(x)) {
            tr[x][op][0] += k;
            tr[x][op][1] += 1;
        }
    };

    auto get = [&](int x, int op, array<int, 2> res = {0, 0}) {
        for ( ; x; x -= lowbit(x)) {
            res[0] += tr[x][op][0];
            res[1] += tr[x][op][1];
        }
        return res;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - '0';
        auto tmp = get(i, c ^ 1);
        (ans += tmp[1] * i - tmp[0]);
        add(i, i, c);
    }

    cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	//cin>>t;
	t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
