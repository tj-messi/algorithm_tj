#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 



void solve()
{
	int n,m,a,b;cin>>n>>m>>a>>b;
	if(n*m%2==1)
	{
		cout<<"No"<<endl;return;
	}
	if(a==0&&b==0)
	{
		if(n*m==2)
		{
			cout<<"Yes"<<endl;return;
		}
		else
		{
			cout<<"No"<<endl;return;
		}
	}
	if(a==1&&b==0)
	{
		if(n==1||m==1)
		{
			cout<<"Yes"<<endl;return;
		}
		else
		{
			cout<<"No"<<endl;return;
		}
	}
	if(a==0&&b==1)
	{
		cout<<"Yes"<<endl;return;
	}
	if(a==1&&b==1)
	{
		cout<<"Yes"<<endl;return;
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
