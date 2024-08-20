#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
tarjan������ǿ��ͨ����
��һ������Ѱ���ӽڵ�Ĺ��̣�һ���С�����ߡ�
��һ����ʼ�����������ݵ�ʱ�����ֱ����low�������low���飬��Ȼֻ����dfn������ ��ֻ����һ�ۣ� 
���һ�����dfn����low�ᱻ�϶�Ϊǿ��ͨ�����ĸ��� 
o(n+m)
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
		tot++;//������ɫ
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
