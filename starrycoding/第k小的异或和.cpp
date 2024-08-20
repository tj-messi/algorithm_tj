#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
01trie:经常处理前缀性质问题 
初始节点是空节点0，动态开节点 
*/
const int N = 2e5+9;
const int p = 998244353;
int a[N];
struct node
{
	int val,son[2];
};
node t[N<<5];
int idx;
struct Q
{
	int id,t,x,k;
};
vector<Q> que;
int ans[N];

void insert(int x)
{
	int o=0;
	t[o].val++;
	for(int i=30;i>=0;i--)
	{
		int y=x>>i & 1;
		int &u = t[o].son[y];
		if(!u)u=++idx;
		o=u;
		t[o].val++;
	}
}

int getVal(int x,int k)
{
	int o=0,res=0;
	for(int i=30;i>=0;i--)
	{
		int y=x>>i &1;
		int u=t[o].son[y];//u是结果小的点，v点的大的点 
		int v=t[o].son[!y];
		if(u && t[u].val>=k)o=u;
		else o=v,k-=u ? t[u].val : 0,res|=1<<i; 
	}
	return res;
}

void solve()
{
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		int t,x,k;cin>>t>>x>>k;
		que.push_back({i,t,x,k});
	}
	sort(que.begin(),que.end(),[](const Q &u,const Q &v)
	{
		return u.t != v.t ? u.t<v.t : u.id < v.id;
	});
	int now=0;
	for(const auto & qe : que)
	{
		while(now<qe.t)insert(a[++now]);
		ans[qe.id] = getVal(qe.x,qe.k);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
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
