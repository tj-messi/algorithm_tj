#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


void solve()
{
	int n;cin>>n;
	string s;cin>>s;
	vector<int> vec(n+2);
	vector<int> prefix (n+2);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0'&&s[i-1]=='1')vec[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+vec[i];
	}
	int q;cin>>q;
	while(q--)
	{
		int l,r;cin>>l>>r;
		cout<<prefix[r-1]-prefix[l-1]<<endl;
	}
}

signed main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
