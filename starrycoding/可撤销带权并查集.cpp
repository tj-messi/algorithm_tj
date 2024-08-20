#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
���鼯����
����ʽ�ϲ�����ͨ�ĺϲ��������ƻ�ԭ�������νṹ����ʱ����ʽ�ϲ�����ԭ������ͨ�������size���ԣ�ÿ��root��sizeС��ָ��size���
������ͨ��һ��stack�ͼ�¼��top����ԭ��һ�� 
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

void merge(int x,int y)//����ʽ�ϲ� 
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
