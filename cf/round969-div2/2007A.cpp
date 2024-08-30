#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


void solve()
{
	int l,r;
	cin>>l>>r;
	int ans=0;
	for(int i=l;i<=r-2;i++)
	{
		if(i%2==1)
		{
			ans++;
			i+=3;
		}
	}
	cout<<ans<<endl; 
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
