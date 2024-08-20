#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
并查集就是查看这个树（图）中点是否互通。解决很多“朋友”问题 
有一种压缩路径的思想就是所有的点如果互连就统一指向根节点，用两个点指向的根点是否一致来判断是否在同一个集合内 
*/
const int N = 1e4+5;
int n,m;
int fa[N];

int root(int x)
{
	return fa[x]=(x==fa[x]?x:root(fa[x]));
} 

void merge(int x,int y)
{
	fa[root(x)]=root(y);
}


void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int op,a,b;cin>>op>>a>>b;
		if(op==1)
		{
			merge(a,b);
		}
		else
		{
			if(root(a)!=root(b))
				cout<<"N"<<endl;
			else
				cout<<"Y"<<endl;
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
