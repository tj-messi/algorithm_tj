#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	int n,m;cin>>n>>m;
	if(n==0&&(m%2==0))
	{
		cout<<"Yes"<<endl;return;
	}
	if(n!=0&&(m%2!=0))
	{
		cout<<"Yes"<<endl;return;
	}
	if(n==0&&(m%2!=0))
	{
		cout<<"No"<<endl;return;
	}
	if(n!=0&&(m%2==0))
	{
		cout<<"No"<<endl;return;
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
