#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
�������LCA
������һ��dp��˼�룬int fa[N][30],fa[i][j]������i��������2^j����ĵ� 
������Ŀ��˼·���ǣ�
1���ȴ���fa���飬ʹ��dp��С����ת��
2���ٴ����lca�������������������ͬһ��ȡ�֮��x��yһ�������������x��y��Ƚ��� 
���Ӷ�o(��Լlogn) 
*/
const int T = 20;
const int N = 2e5+9;
vector<int> mp [N];
int fa[N][30];
int dep[N];//��¼��� 

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
	if(dep[x]<dep[y])swap(x,y);//����dep[x]����
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
