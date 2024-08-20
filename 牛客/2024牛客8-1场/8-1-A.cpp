#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 2e5+5;
struct node
{
	int now, w;//儿子点，权重 
};
//int fa[N];//记录父亲节点 
//double nowscore[N];//奥斯卡拿的最好成绩 
//int dep[N];//偶数时候格莱美贪心，奇数时候奥斯卡贪心 
//double ans=0;
int vis[N];
vector<vector<node>> t (N);//记录每个点的儿子 
double dfs(int p,double cnt1,double cnt0,double nowbest,int depth)
{
	//nowscore[p]=nowbest;//标记奥斯卡成绩 
	//dep[p]=depth;//标记深度 
	if(t[p].empty())//走到根节点 
	{
		return nowbest;
	}
	double maxnow=0,minnow=1.5;
	for(auto s : t[p])
	{
		if(vis[s.now]==0)continue;
		vis[s.now]=1;
		if(s.w==0)
		{
			double nnowbest=max(nowbest,(1+cnt0)/(cnt1+cnt0+1));
			maxnow=max(dfs(s.now,cnt1,cnt0+1,nnowbest,depth+1),maxnow);
			minnow=min(dfs(s.now,cnt1,cnt0+1,nnowbest,depth+1),minnow);
		}
		else if(s.w==1)
		{
			maxnow=max(dfs(s.now,cnt1+1,cnt0,nowbest,depth+1),maxnow);
			minnow=min(dfs(s.now,cnt1+1,cnt0,nowbest,depth+1),minnow);
		}
	}
	if(depth%2==0)
	{
		nowbest=minnow;
	}
	else nowbest=maxnow;
	return nowbest;
}

void solve()
{
	//memset(nowscore,0,sizeof nowscore); 
	//ans=0;
	memset(vis,0,sizeof vis);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		t[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int f,s,w;
		cin>>f>>s>>w;
		t[f].push_back({s,w});
		t[s].push_back({f,w});
		//fa[s]=f;
	}
	//cout;//先跑一遍看答案 
	/*for(int i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(10)<<nowscore[i]<<endl;
		cout<<dep[i]<<endl;
	}*/
	
	cout<<fixed<<setprecision(12)<<1-dfs(1,0,0,0,0)<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	//t=1;
	while(t--)
	{
		solve();
	}
	return 0;
} 
