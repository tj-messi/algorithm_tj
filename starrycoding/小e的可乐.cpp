#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
���鼯����
����ʽ�ϲ�����ͨ�ĺϲ��������ƻ�ԭ�������νṹ����ʱ����ʽ�ϲ�����ԭ������ͨ�������size���ԣ�ÿ��root��sizeС��ָ��size���
������ͨ��һ��stack�ͼ�¼��top����ԭ��һ��
��Ȩ���鼯������һЩ��������⣬ ������d[N]����ʾ�ڵ�i�����׵ľ��� 
*/
const int N = 2e5+5;
int n,m;
int fa[N],sz[N],d[N];

int mo(int x)
{
	return (x%2+2)%2;
}

int root(int x)
{
	return fa[x]=(x==fa[x]?x:root(fa[x]));
} 

int getd(int x)
{
	int res=0;
	while(x!=fa[x])
	{
		res+=d[x];
		x=fa[x];
	}
	return res;
}


void merge(int x,int y)
{
	int fx=root(x);int fy=root(y);
	if(fx==fy)return;
	if(sz[fx]>sz[fy])swap(fx,fy);
	sz[fy]+=sz[fx];
	fa[fx]=fy;
	d[fx]=mo(getd(x)-getd(y)-1);
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;sz[i]=1;d[i]=0;
	} 
	for(int i=1;i<=m;i++)
	{
		int op,x,y;cin>>op>>x>>y;
		if(op==1)
		{
			merge(x,y);
		}
		else
		{
			int rx=root(x);int ry=root(y);
			if(rx!=ry)cout<<"Unknown"<<endl;
			else if(mo(getd(x)-getd(y))==1)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
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
