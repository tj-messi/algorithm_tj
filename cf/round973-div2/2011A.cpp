#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


void solve()
{
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	int u=min(x,y);
	if(n%u==0)
	{
		cout<<n/u<<endl;
	}
	else
		cout<<n/u+1<<endl;
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
