#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define endl '\n' 
 
 
 
void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n + 1, 1);
 
	for (int i = y - 1, s = -1; i >= 1; i--) {
		a[i] = s;
		s *= -1;
	}
	for (int i = x + 1, s = -1; i <= n; i++) {
		a[i] = s;
		s *= -1;
	}
 
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
	}
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
