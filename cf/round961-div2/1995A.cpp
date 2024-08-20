#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 



void solve()
{
	int n,k;cin>>n>>k;
	int ans=0;
	if(k<=n)
	{
		cout<<min(k,1ll)<<endl;
		return;
	}
	ans++;k-=n;n--;
	while(k>0)
	{
		k-=n;ans++;
		if(k<=0)break;
		k-=n;ans++;
		n--;
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
