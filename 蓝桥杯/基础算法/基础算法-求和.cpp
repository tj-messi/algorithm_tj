#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e5+5;

void solve()
{
	int n;cin>>n;
	vector<int> v (n+1) , prefix (n+1);
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+v[i];
	}
	int sum = 0;
	for(int i=1;i<n;i++)
	{
		sum+=v[i]*(prefix[n]-prefix[i]);
	} 
	cout<<sum<<endl;
}

signed main()
{
	int t = 1;
	//cin>>t
	while(t--)
	{
		solve();
	}
	return 0;
}
