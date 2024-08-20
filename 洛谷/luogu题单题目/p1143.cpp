#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	int n;cin>>n;
	string s;cin>>s;
	int m;cin>>m;
	int cnt=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		cnt*=n;
		if(s[i]>='A'&&s[i]<='Z')
		{
			cnt+=s[i]-'A'+10;
		}
		else	cnt+=s[i]-'0';
	}
	//cout<<cnt<<endl;
	vector<char> v;
	while(cnt)
	{
		int temp=cnt%m;
		cnt/=m;
		v.push_back(temp+'0');
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i]>=10+'0')
		{
			cout<<char(v[i]-10-'0'+'A');
		}
		else cout<<v[i];
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
