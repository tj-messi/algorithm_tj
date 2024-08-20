#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 2e6+6;
int a[N];

void solve()
{
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(q--)
	{
		int idx;cin>>idx;
		cout<<a[idx]<<endl;
	}
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
