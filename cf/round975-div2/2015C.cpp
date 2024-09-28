#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 2e5+5;
int a[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	int sum=0;
	int maxnum=0;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];maxnum=max(maxnum,a[i]);
		sum+=a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		int les = sum % i;
		int ros=(i-les)%i;
		if(ros>k)continue;
		//else
		//{
			int num=sum+k-((k-ros)%i);
			int g=num/i;
			if(g>=maxnum)
			{
				ans=max(ans,i);
			}
		//}
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
