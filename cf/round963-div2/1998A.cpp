#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 10;
int ans[N];

void solve()
{
	int n;cin>>n;
	memset(ans,0,sizeof ans);
	for(int i=1;i<=4*n;i++)
	{
		char now;cin>>now;
		if(now=='?')continue;
		ans[now-'A'+1]++;
	}
	int res=0;
	for(int i=1;i<=4;i++)
	{
		res+=min(ans[i],n);
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
