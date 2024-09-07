#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	string s;
	cin>>s;
	int l=s.find('[');
	int r=s.find(']');
	cout<<"/";
	for(int i=l;i<=r;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			cout<<char(s[i]+'a'-'A');
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
