#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	string s;cin>>s;
	int cnt1=0;//四星保底
	int cnt2=0;//小保底90
	int cnt3=0;//大保底 
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='3')
		{
			cnt1++;cnt2++;
		}
		if(s[i]=='4')
		{
			cnt2++;cnt1=0;
		}
		if(s[i]=='5')
		{
			cnt3++;cnt2=0;cnt1=0;
		}
		if(s[i]=='U')
		{
			cnt1=0;cnt2=0;cnt3=0;
		}
		if(cnt1>=10||cnt2>=90||cnt3>=2)
		{
			cout<<"invalid"<<endl;return;
		}
	}
	cout<<"valid"<<endl;
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
