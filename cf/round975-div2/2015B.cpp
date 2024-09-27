#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

void solve()
{
	int n,q;cin>>n>>q;
	vector<int>arr(n);
	map<int, int>m;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		
		for (int i = 1; i < n; ++i)
		{
			m[i * (n - i)] += arr[i] - arr[i - 1] - 1;
		}

		for (int i = 0; i < n; ++i)
		{
			int op = n - i - 1;
			int C = (i) * (op)+n - 1;
			m[C] += 1;
		}
		for (int i = 0; i < q; ++i)
		{
			int x;
			cin >> x;
			cout << m[x] << " ";
		}
		cout << endl;
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
