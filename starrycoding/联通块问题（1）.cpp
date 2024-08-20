#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
并查集进阶
启发式合并：普通的合并会严重破坏原本的树形结构，此时启发式合并，对原本的联通块加上了size属性，每次root把size小的指向size大的
 
*/
const int N = 2e5+5;
int n,m;
int fa[N];
int sz[N];
int a[N];

int root(int x)
{
	return fa[x]=(x==fa[x]?x:root(fa[x]));
} 

void merge(int x,int y)
{
	int fx=root(x);int fy=root(y);
	if(fx==fy)return;
	if(sz[fx]>sz[fy])swap(fx,fy);
	fa[fx]=fy;
	sz[fy]+=sz[fx];
}


void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		merge(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(fa[(i)]!=i)a[root(i)]^=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(fa[(i)]==i)ans=max(ans,a[i]);
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
