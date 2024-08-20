#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
���鼯���ǲ鿴�������ͼ���е��Ƿ�ͨ������ܶࡰ���ѡ����� 
��һ��ѹ��·����˼��������еĵ����������ͳһָ����ڵ㣬��������ָ��ĸ����Ƿ�һ�����ж��Ƿ���ͬһ�������� 
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
