#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5+5;
int a[N];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=2;i<=n-1;i++)
	{
		if(a[i]>=a[i-1]+a[i+1])ans++;
	}
	cout<<ans<<endl;
}

signed main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
