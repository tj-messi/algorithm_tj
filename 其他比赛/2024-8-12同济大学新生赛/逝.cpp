#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

struct node
{
	int x,y,w;
	bool operator < (const auto &u)const
	{
		return 	w < u.w;
	};
};
const int N = 2e3+5;
int X[N],Y[N];
int fa[N];

int root(int x)
{
	return fa[x]=(fa[x]==x ? x : root (fa[x]));
}


void solve()
{
	int w,h,n;
	cin >> w >> h >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> X[i]>> Y[i];
	}
	
	int ans=0;

	vector<node> tree ;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			tree.push_back({i,j,(ll)(abs(X[i]-X[j])+abs(Y[i]-Y[j]))/2});
		}
	}
	
	for(int i=1;i<=n;i++)fa[i]=i;
	
	sort(tree.begin(),tree.end());
	
	for (auto &[x,y,w] : tree)
	{
		if(root(x)==root(y))continue;
		ans=w;
		fa[root(x)]=root(y);
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
