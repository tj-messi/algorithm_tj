#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
tarjan求无向图的割点和割边
对于一个割点和割边。tarjan的dfn和low数组之间的特殊关系可以确认他是不是一个割点和割边
关系如下：
cnt[y]>dfn[x]是一个割边
cnt[y]>=dfn[x]是一个“不回儿子”，如果是根的话需要两个不回儿子，如果不是根的话需要一个不回儿子。满足这个1条件就是割点 
*/

const int N = 2e5+9;
vector<int> g [N];
int dfn[N];//时间戳
int low[N];//最短的更新戳
int top,idx;
//int col[N];//把强联通分量标记颜色
int cnt1,cnt2;//cnt可以记录强联通量的大小 


void tarjan1(int x,int fa)
{
	dfn[x]=low[x]=++idx;
	
	int child=0;
	for(auto y : g[x])
	{
		if(y==fa)continue;
		if(!dfn[y])
		{
			tarjan1(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>low[x])cnt2++;//割边的判断增加 
			child+=(low[y]>=dfn[x]);//不回儿子的判断 
		}
		else low[x]=min(low[x],dfn[y]);
	}
	
	if((!fa&&(child>=2))||(fa&&(child>=1)))cnt1++;//割点的判断增加 
}

void solve()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])tarjan1(i,0);	
	} 
	cout<<cnt1<<" "<<cnt2<<endl;
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
