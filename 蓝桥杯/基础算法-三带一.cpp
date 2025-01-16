#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'




void solve()
{
	map<char,int> mp;
	string s;cin>>s;
	for(int i=0;i<4;i++)mp[s[i]]++;
	int flag3 = false;
	for(auto [c,i]:mp)
	{
		if(i==3)flag3=true;
	}
	if(flag3)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

signed main()
{
	int t = 1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
