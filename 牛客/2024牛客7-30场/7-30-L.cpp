#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int m = 998244353;
const int N = 105;
vector<int> a(N);

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=accumulate(a.begin()+i,a.end(),0ll);
		for(int j=n;j>i;j--)
		{
			if(a[j]*(j-i+1)>sum)
			{
				int t=ceil(1.0*sum/(j-i+1));
				int k=a[j]-t;
				a[j-1]+=k;
				a[j]-=k;
			}
			sum-=a[j];
		}
	}
	int res=1;
	for(int i=1;i<=n;i++)
	{
		(res*=a[i])%=m;
	}
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
