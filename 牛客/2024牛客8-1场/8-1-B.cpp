#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	int n,k;cin>>n>>k;
	k=min(k,n-k);
	if(2*k==n)
	{
		cout<<n<<endl;
	}
	else
	{
		cout<<n*k+1<<endl;
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
