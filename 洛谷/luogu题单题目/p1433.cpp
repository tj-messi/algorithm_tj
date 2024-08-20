#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 25;
double dp[N][35000];//dp[i][s]表示目前状态是s，停在i位置的最优答案-最小 
int n;
struct node
{
	double x,y;
};
node p[N];
const double inf=1000000005;
double dis(node p1,node p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void solve()
{
	memset(dp,127,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
	p[0].x=0;p[0].y=0;
	//for(int i=0;i<35000;i++) {
	//	for(int j=0;j<=20;j++) dp[j][i]=inf;
	//}
	dp[0][1]=0;
	for(int i=1;i<1<<(n+1);i++)
	{
		for(int j=1;j<=n;j++)
		if((i>>(j))&1)
		{  
			for(int k=0;k<=n;k++)
			{
				if(((i^(1<<j))>>k)&1)
				{
					dp[j][i]=min(dp[j][i],dp[k][i^(1<<j)]+dis(p[k],p[j]));
				}
			}
		}
	}
	double ans=inf;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,dp[i][(1<<(n+1))-1]);
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
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
