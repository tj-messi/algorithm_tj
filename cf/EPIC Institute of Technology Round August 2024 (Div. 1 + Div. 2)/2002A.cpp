#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


void solve()
{
	int n,m,k;cin>>n>>m>>k;
	int maxl=max(n,m);
	int res=1;
	if(k>=n) res*=n;
	else res*=k;
	if(k>=m) res*=m;
	else res*=k;
	cout<<res<<endl;
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
