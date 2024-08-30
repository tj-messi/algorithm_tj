#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 1e5+5;
int a[N];


void solve()
{
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(a[i],ans);
	}
	while(m--)
	{
		char op;cin>>op;
		int l,r;cin>>l>>r;
		if(op=='+')
		{
			if(r>=ans&&l<=ans)ans++;
		}
		else
		{
			if(r>=ans&&l<=ans)ans--;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
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
