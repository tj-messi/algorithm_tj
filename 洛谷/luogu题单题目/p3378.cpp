#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


void solve()
{
	int n;cin>>n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=1;i<=n;i++)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x;cin>>x;
			pq.push(x);
		}
		else if(op==2)
		{
			cout<<pq.top()<<endl;
		}
		else
		{
			pq.pop();
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
