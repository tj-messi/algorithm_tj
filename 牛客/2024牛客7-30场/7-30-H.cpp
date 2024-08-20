#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> mp (n+1);
	vector<int> vis(n+1);
	for(int i=1;i<=m;i++)
	{
		int x;int y;cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	int ans=0;
	auto dfs=[&](auto self,int x,int fa,int s)->void
	{
		ans=max(ans,s);
		for(auto y : mp[x])
		{
			if(vis[y])continue;
			int fl=0;
			for(int yy : mp[y])
			{
				if(yy!=y&&vis[yy])
				{
					fl=1;break;
				}
			}
			if(fl)continue;
			vis[x]=1;
			self(self,y,x,s+1);
			vis[x]=0;
		}
	};
	
	for(int i=1;i<=n;i++)
	{
		vis.assign(n+1,0);
		dfs(dfs,i,0,1);
	}
	
	cout<<ans<<endl;
	
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
