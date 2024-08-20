#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
kruskal 最小生成树算法。把一个图中选定一定的边权，使得耗费最小
贪心的想法，从最小的边权开始选择，如果两个点已经联通，那么就不选。
复杂度o(mlogm) 
相对于prim算法，kruskal适合简单图--因为他的复杂度和边挂钩 
*/
const int N = 2e5+5;
int n,m,tot=0,k=0;
int fa[N]; 
struct node
{
	int from,to,w;
};
node edge[N];
bool cmp(node n1,node n2)
{
	return n1.w<n2.w;
}
int root(int x)
{
	return fa[x]=(fa[x]==x?x:root(fa[x]));
}
void merge(int a,int b)
{
	fa[root(a)]=root(b);
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].from>>edge[i].to>>edge[i].w;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(k==n-1)break;//链接完毕
		if(root(edge[i].from)!=root(edge[i].to))
		{
			merge(edge[i].from,edge[i].to);
			tot+=edge[i].w;
			k++;
		} 
	}
	cout<<tot<<endl;
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
