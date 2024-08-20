#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


void solve()
{
	int x,y,k;cin>>x>>y>>k;
	if(k%2==1)
	{
		for(int i=-(k/2);i<=(k/2);i++)
		{
			cout<<i+x<<" "<<i+y<<endl;
		}
	}
	else
	{
		for(int i=-(k/2);i<=(k/2);i++)
		{
			if(i!=0)
				cout<<i+x<<" "<<i+y<<endl;
		}
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
