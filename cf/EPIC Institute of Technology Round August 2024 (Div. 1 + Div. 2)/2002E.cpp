#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 3e5+5;
struct node1
{
	int len,i;
	bool operator < (const auto u)const
	{
		return len>u.len;	
	};	
};
struct node
{
	int len,num;
};
node pre[N];

void solve()
{
	priority_queue<node1> pq;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i].len>>pre[i].num;
		pq.push({pre[i].len,i});
	}
	/*for(int i=1;i<=n;i++)
	{
		auto now = pq.top();pq.pop();
		cout<<now.i<<" "<<now.len<<endl;
	}*/
	
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
