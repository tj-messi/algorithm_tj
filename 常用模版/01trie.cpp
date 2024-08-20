#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
01trie:��������ǰ׺�������� 
��ʼ�ڵ��ǿսڵ�0����̬���ڵ� 
*/
const int N = 2e5+9;
const int p = 998244353;
int a[N];
struct node
{
	int val,son[2];
};
node t[N*32];
int idx;

void insert(int x)
{
	int o=0;
	for(int i=30;i>=0;i--)
	{
		int y=x>>i&1;
		int &u=t[o].son[y];
		if(!u)u=++idx;
		o=u;
	}
}

int getmax(int x)
{
	int o=0;int res=0;
	for(int i=30;i>=0;i--)
	{
		int y=x>>i&1;
		int u=t[o].son[y],v=t[o].son[!y];
		if(v)o=v,res|=(1<<i);
		else o=u;
	}
	return res;
}

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	insert(a[1]);
	int ans=a[1]^a[2];
	for(int i=2;i<=n;i++)
	{
		insert(a[i]);
		ans=max(ans,getmax(a[i]));
	}
	cout<<ans<<endl;
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
