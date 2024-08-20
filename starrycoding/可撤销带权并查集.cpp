#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
并查集进阶
启发式合并：普通的合并会严重破坏原本的树形结构，此时启发式合并，对原本的联通块加上了size属性，每次root把size小的指向size大的
撤销：通过一个stack和记录的top来还原上一步 
*/
const int N = 2e6+5;
int n,m;
int fa[N];
int sz[N];
int a[N];
int top=0;

pair<int,int> stk[N]; 

int root(int x)
{
	return (x==fa[x]?x:root(fa[x]));
} 

void merge(int x,int y)//启发式合并 
{
	int fx=root(x);int fy=root(y);
	if(fx==fy)return;
	if(sz[fx]>sz[fy])swap(fx,fy);
	stk[++top]={fx,fy};
	sz[fy]+=sz[fx];
	fa[fx]=fy;
}

void undo()
{
	if(!top)return;
	auto [x,y]=stk[top--];
	fa[x]=x;
	sz[y]-=sz[x];
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x,y;cin>>x>>y;
			merge(x,y);
		}
		else if(op==2)
		{
			undo();
		}
		else
		{
			int x,y;cin>>x>>y;
			cout<<(root(x)==root(y) ? "YES" : "NO")<<endl;
		}
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
