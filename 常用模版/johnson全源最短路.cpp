#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
Johnson算法
可以对每一个点表达出一个势能函数h【】
再改变每一个边权w=w+h[x]-h[y]；其中x是源，y是目标
再跑dijkstra
最后还原dp[x][y]距离=dp[x][y]-h[x]+h[y] 
*/

const int inf=4e18;
const int N = 3e3+5;
bool vis [N];
int h[N],d[N][N],n,m;
struct edge
{
	int x,w;
	bool operator < (const edge &u)const
	{
		return w>u.w;
	}
};
vector<edge> g[N];

void dijkstra(int st,int d[])
{
	for(int i=1;i<=n;i++)d[i]=inf;
	priority_queue<edge> pq;
	memset(vis,false,sizeof vis);
	pq.push({st,d[st]=0});
	while(pq.size())
	{
		int x=pq.top().x;pq.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(auto [y,w] : g[x])
		{
			if(d[y]>d[x]+w)
			{
				d[y]=d[x]+w;
				pq.push({y,d[y]});
			}
		}
	}
	for(int i=1;i<=n;i++)d[i]=d[i]-h[st]+h[i];
}

bool spfa(int st)
{
	for(int i=1;i<=n;i++)h[i]=inf;
	bitset<N> inq;
	queue<int> q;
	vector<int> cnt(n+1);
	inq[st]=true;
	q.push(st);
	while(q.size())
	{
		int x=q.front();q.pop();inq[x]=false;
		for(auto &[y,w] : g[x])
		{
			if(h[y]>h[x]+w)
			{
				if(++cnt[y]>=n)return true;
				h[y]=h[x]+w;
				if(!inq[y])q.push(y),inq[y]=true;
			}
		}
	}
	return false;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;cin>>x>>y>>w;
		g[x].push_back({y,w});
	}
	for(int i=1;i<=n;i++)
	{
		g[0].push_back({i,0});
	}
	if(spfa(0))
	{
		cout<<"starrycoding"<<endl;
		return;
	}
	for(int x=1;x<=n;x++)
	{
		for(auto &[y,w] : g[x])w=w+h[x]-h[y];
	}
	for(int i=1;i<=n;i++)dijkstra(i,d[i]); 
	int q;cin>>q;
	while(q--)
	{
		int x,y;cin>>x>>y;
		if(d[x][y]>=inf/2)cout<<"noway"<<endl;//松弛不会超过这个范围 
		else cout<<d[x][y]<<endl;
	}
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
