#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 
 
const int N = 2e5+4;
 
 
 
 
void solve()
{
	int ans=0;
	int n;cin>>n;
	vector<ll> a(n + 1), b(n + 1);
	map<int, int> mp,c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];ans+=a[i];//累加过第一次的 
	}
	ll j = 0;
	for (int i = 1; i <= n; i++) {
		mp[a[i]]++;
		if (mp[a[i]] > 1) j = max(j, a[i]);
		b[i] = j;
		c[j]++;
	}
 
	ll res = 0;
	j = 0;
	for (int i = 1; i <= n; i++) {
		ans += res + b[i];
		if (c[b[i]] >= 2) {
			res += b[i];
			j = b[i];
		} else {
			res += j;
		}
	}
 
	cout << ans << "\n";
}
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	//t=1;
	while(t--)
	{
		solve();
	}
	return 0;
} 
