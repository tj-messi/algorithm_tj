#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 1e5+5;
int a[N],b[N];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int ans=0;
	int num=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])ans++;
		if(a[i]==b[i])num++;
	}
	cout<<ans+num/2<<endl;
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
