#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
tarjan������ͼ�ĸ��͸��
����һ�����͸�ߡ�tarjan��dfn��low����֮��������ϵ����ȷ�����ǲ���һ�����͸��
��ϵ���£�
cnt[y]>dfn[x]��һ�����
cnt[y]>=dfn[x]��һ�������ض��ӡ�������Ǹ��Ļ���Ҫ�������ض��ӣ�������Ǹ��Ļ���Ҫһ�����ض��ӡ��������1�������Ǹ�� 
*/

const int N = 2e5+9;
vector<int> g [N];
int dfn[N];//ʱ���
int low[N];//��̵ĸ��´�
int top,idx;
//int col[N];//��ǿ��ͨ���������ɫ
int cnt1,cnt2;//cnt���Լ�¼ǿ��ͨ���Ĵ�С 


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
			if(low[y]>low[x])cnt2++;//��ߵ��ж����� 
			child+=(low[y]>=dfn[x]);//���ض��ӵ��ж� 
		}
		else low[x]=min(low[x],dfn[y]);
	}
	
	if((!fa&&(child>=2))||(fa&&(child>=1)))cnt1++;//�����ж����� 
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
