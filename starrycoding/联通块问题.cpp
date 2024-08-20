#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
并查集就是查看这个树（图）中点是否互通。解决很多“朋友”问题 
有一种压缩路径的思想就是所有的点如果互连就统一指向根节点，用两个点指向的根点是否一致来判断是否在同一个集合内 
*/
const int N = 2e5+5;
vector<int> g [N];
int fa[N];
int cnt[N];
int n,m;

int root(int x)
{
	return fa[x]=(fa[x]==x ? x : root(fa[x]));
}

void merge(int x,int y)
{
	fa[root(x)]=root(y);
}

void solve()
{
	cin>>n>>m;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		merge(x,y);
	} 
	
	for(int i=1;i<=n;i++)
	{
		cnt[root(i)]++;
	}
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i])v.push_back(cnt[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<=v.size()-1;i++)
	{
		cout<<v[i]<<" ";
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
