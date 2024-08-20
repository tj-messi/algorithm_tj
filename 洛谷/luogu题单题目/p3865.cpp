#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
st表：
借用倍增的思路，进行高效的区间查询 
*/
const int N = 1e5+5;
int n,m;
int a[N];
int st[N][30];

void st_init()
{
	for(int i=1;i<=n;i++)st[i][0]=a[i];
	int k=log2(n);
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=(n-(1<<j)+1);i++)
		{
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int l,int r)
{
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	st_init();
	for(int i=1;i<=m;i++)
	{
		int l,r;cin>>l>>r;
		cout<<query(l,r)<<endl;
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
