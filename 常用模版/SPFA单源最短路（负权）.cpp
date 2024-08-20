#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
SPFA就是bellman-fold的队列优化版本，负责解决负权图问题，复杂度 o(m)~o(n*m);
*/

const int N=1e4+5;
int n,m,d[N],inf=2e18;
struct node{
    int y,w;
};
vector<node>g1[N];
bool spfa(int st){
    bitset<N>inq;
    queue<int>q;
    q.push(st);
    d[st]=0;
    vector<int>cnt(n+2);
    while(q.size()){
        int x=q.front();q.pop();inq[x]=false;
        for(auto [y,w]:g1[x]){
            if(d[x]+w<d[y]){
                if(++cnt[y]>=n)return true;
                d[y]=d[x]+w;
                if(!inq[y])q.push(y),inq[y]=true;
            }
        }
    }
    return false;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
    	int x,y,w;cin>>x>>y>>w;
    	g1[x].push_back({y,w});
    	//g1[y].push_back({x,w});
	}
	for(int i=1;i<=n;i++)d[i]=inf;
	if(spfa(1)){
    	cout<<"-1";
    	return;
	}
	else{
    	for(int i=1;i<=n;i++)cout<<d[i]<<" ";
	}
return;
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
