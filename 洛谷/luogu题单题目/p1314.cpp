#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


//二分答案吧 
const int N = 2e5+5;
int n,m,s;
int l=0;int r=0;
struct node
{
	int w,v;//重量、价值 
};
node a[N];
struct que
{
	int l,r;//左右区间 
};
que q[N];
int pre[N];int prenum[N];//v的前缀，数量的前缀

int check(int W)
{
	int res=0;
	memset(pre,0,sizeof pre);
	memset(prenum,0,sizeof prenum); 
	for(int i=1;i<=n;i++)
	{
		if(a[i].w>=W)
		{
			pre[i]=pre[i-1]+a[i].v;
			prenum[i]=prenum[i-1]+1;
		}
		else
		{
			pre[i]=pre[i-1];
			prenum[i]=prenum[i-1];
		} 
	}
	for(int i=1;i<=m;i++)
	{
		res+=(prenum[q[i].r]-prenum[q[i].l-1])*(pre[q[i].r]-pre[q[i].l-1]);
	}
	return res;
}

void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i].w>>a[i].v;
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r;
	for(int i=1;i<=n;i++)
	{
		r=max(r,a[i].w);
	}
	//cout<<"debug"<<endl;
	while(l+1<r)
	{
		int mid=(r+l)>>1;
		//cout<<mid<<endl;
		if(check(mid)>=s)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<min(llabs(check(r)-s),llabs(check(l)-s))<<endl;
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
