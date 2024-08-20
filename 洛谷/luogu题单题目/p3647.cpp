#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
floyd求多源的最短路，适用于任何图，复杂度o（n^3）； 
用dp[i][j]表示从i到j的最短路
*/
const int inf = 0x3f3f3f3f3f3f;
const int N = 1e2+5;
int n,m;
int dp[N][N];//用邻接矩阵 
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=min(min(dp[i][j],dp[j][i]),dp[i][k]+dp[k][j]);
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	memset(dp,inf,sizeof dp);
	for(int i=1;i<=n;i++)dp[i][i]=0ll;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		dp[u][v]=min(dp[u][v],w); 
		dp[v][u]=min(dp[v][u],w); 
	}
	floyd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
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
