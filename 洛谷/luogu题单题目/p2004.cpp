#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 2e3+5;
int n,m,c;
int mp[N][N];
int pre[N][N];
struct node
{
	int x,y;	
};

void solve()
{
	cin>>n>>m>>c;
	memset(pre,0,sizeof pre);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cin>>mp[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			pre[i][j]=pre[i-1][j]+pre[i][j-1]+mp[i][j]-pre[i-1][j-1];
		}
	}
	node ans={0,0};int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j+c-1>m||i+c-1>n)continue;
			int temp=pre[i+c-1][j+c-1]-pre[i+c-1][j-1]-pre[i-1][j+c-1]+pre[i-1][j-1];
			if(temp>sum)
			{
				sum=temp;
				ans={i,j};
			}
		}
	}
	cout<<ans.x<<" "<<ans.y<<endl;
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
