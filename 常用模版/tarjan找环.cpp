#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
tarjan������ͼ�Ļ����൱����һ��ǿ��ͨ������ 
*/

const int N = 2e5+9;
vector<int> g [N];
int dfn[N];//ʱ���
int low[N];//��̵ĸ��´�
int stk[N];//��������������stk
int top,idx;
//int col[N];//��ǿ��ͨ���������ɫ
int tot,cnt[N];//cnt���Լ�¼ǿ��ͨ���Ĵ�С 
bitset<N> ins; //����Ƿ����� 
int ans=0;

void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++idx;
	stk[++top]=x;
	ins[x]=true;
	
	for(auto y : g[x])
	{
		if(y==fa)continue;
		if(!dfn[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else if(ins[y])low[x]=min(low[x],dfn[y]);
	}
	
	if(low[x]==dfn[x])
	{
		int cnt=0;
		while(stk[top+1]!=x)
		{
			cnt++;
			ins[stk[top--]]=false;
		 } 
		 if(cnt>1)
		 {
		 	ans=cnt;return;
		 }
	}
	
}

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		stk[i]=dfn[i]=low[i]=0;
		ins[i]=false;
	}
	stk[n+1]=0;
	ans=idx=top=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])tarjan(i,0);	
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	//t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
