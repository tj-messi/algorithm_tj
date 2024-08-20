#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
prim最小生成树算法，通过每个点开始枚举接下来的边到达的点，选一个最小的连过去。
复杂度o((n+m)logn)
相比于kruskal ,prim更加适合稠密图---因为他的复杂度主要和点的数量挂钩而不是边 
*/
const int inf = 1e18+5;
const int N = 1e6+5;
int n,m,dp[N];
int ans=0;
int vis[N];//标记是否走过
struct node
{
	int to,w;
	bool operator < (const node &u)const
	{
		return w>u.w;
	}
}; 
vector<vector<node>> edge (N+1);
priority_queue<node> pq;

void prim()
{
	pq.push({1,0});
	dp[1]=0;
	while(!pq.empty())
	{
		node now=pq.top();pq.pop();
		if(vis[now.to])continue;
		vis[now.to]=1;
		ans+=now.w;
		for(auto next : edge[now.to])
		{
			if(dp[next.to]>next.w)
			{
				dp[next.to]=next.w;
				pq.push({next.to,next.w});
			}
		}
	}
}

void solve()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	} 
	memset(dp,0x3f,sizeof dp);
	prim();
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			cout<<"no tree"<<endl;return; 
		}
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
