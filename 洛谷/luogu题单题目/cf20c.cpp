#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
dijkstra��Դ�����·���������رߣ��Ի��������и��ı�Ȩ(��ʱ����spfa)�����Ӷ�o(nlogn+m); 
��Ҫ��������Ż�һ�� 
*/
const int inf = 0x3f3f3f3f3f3f;
const int N = 1e5+5;
int n,m;
struct node
{
	int to,w;
	//С���ѵ��Ż� 
	bool operator < (const node &v)const
	{
		return w==v.w ? to < v.to : w>v.w;
	}
};
vector<node> mp[N];
int dp[N];int fa[N];//��¼ÿ��������·�ĸ��׽ڵ� 
vector<int> ans;//������ 

void dijkstra(int st)
{
	memset(dp,(long long)inf,sizeof dp);
	dp[st]=0;
	bitset<N> vis;
	priority_queue<node> pq;
	pq.push({st,dp[st]});
	while(!pq.empty())
	{
		node now=pq.top();pq.pop();
		if(vis[now.to])continue;
		vis[now.to]=true;
		for(auto next : mp[now.to])
		{
			if(!vis[next.to]&&dp[next.to]>dp[now.to]+next.w)
			{
				dp[next.to]=dp[now.to]+next.w;
				pq.push({next.to,next.w});
				fa[next.to]=now.to;
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)fa[i]=-1;
	dijkstra(1);
	bool flag=true;
	int idx=n;
	while(fa[idx]!=-1)
	{
		ans.push_back(fa[idx]);
		if(fa[idx]==1)
		{
			flag=false;break;
		}
		idx=fa[idx];
	}
	if(flag)cout<<-1<<endl;
	else
	{
		for(int i=ans.size()-1;i>=0;i--)
		{
			cout<<ans[i]<<" "; 
		}
		cout<<n;
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
