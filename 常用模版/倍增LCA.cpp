#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
倍增解决LCA
采用了一个dp的思想，int fa[N][30],fa[i][j]代表结点i向上走了2^j到达的点 
整个题目的思路就是：
1：先处理fa数组，使用dp从小到大转移
2：再处理出lca：深的先往上跳，跳到同一深度。之后x，y一起往上跳，如果x和y相等结束 
复杂度o(大约logn) 
*/
const int T = 20;
const int N = 2e5+9;
vector<int> mp [N];
int fa[N][30];
int dep[N];//记录深度 

void dfs(int x)
{
	for(int i=1;i<=T;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto &y : mp[x])
	{
		dep[y]=dep[x]+1;
		dfs(y);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);//加深dep[x]最深
	for(int i=T;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=T;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0]; 
}

void solve()
{
	int n;cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>fa[i][0];
		mp[fa[i][0]].push_back(i);
	}
	dep[1]=1;
	dfs(1); 
	int q;cin>>q;
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<lca(x,y)<<endl;
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
