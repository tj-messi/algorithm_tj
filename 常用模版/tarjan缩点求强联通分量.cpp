#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
tarjan缩点求强联通分量
是一个向下寻找子节点的过程，一旦有“返祖边”
找一个初始的搜索树回溯的时候可以直接用low数组更新low数组，不然只能用dfn来更新 （只看了一眼） 
如果一个点的dfn等于low会被认定为强联通分量的根。 
o(n+m)
*/

const int N = 2e5+9;
vector<int> g [N];
int dfn[N];//时间戳
int low[N];//最短的更新戳
int stk[N];//用来存搜索树的stk
int top,idx;
//int col[N];//把强联通分量标记颜色
int tot,cnt[N];//cnt可以记录强联通量的大小 
bitset<N> ins; //标记是否进入过 

void tarjan(int x)
{
	dfn[x]=low[x]=++idx;
	
	stk[++top]=x;
	ins[x]=true;
	
	for(auto y : g[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(ins[y])low[x]=min(low[x],dfn[y]);
	}
	
	if(low[x]==dfn[x])
	{
		tot++;//开新颜色
		while(stk[top+1]!=x)
		{
			cnt[tot]++;
			ins[stk[top--]]=false;
		 } 
	}
}

void solve()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])tarjan(i);	
	} 
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>1)
			v.push_back(cnt[i]);
	}
	if(v.size())
	{
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
	}
	else cout<<-1<<endl;
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
