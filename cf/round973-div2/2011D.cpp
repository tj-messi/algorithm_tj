#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

int qry(string s)
{
	cout<<"? "<<s<<endl;
	int res;cin>>res;
	return res;
}

	

void solve()
{
	int n;cin>>n;
	string now="";
	bool flag=0;
	while(n--)
	{
		if(flag)
		{
			if(qry(now+"0"))//now+0ÊÇ 
			{
				now=now+"0";
			}
			else if(qry(now+"1"))//now+1ÊÇ 
			{
				now=now+"1";
			}
			else
			{
				n++;
				flag=true;
			}
		}
		else
		{
			if(qry("0"+now))
			{
				now="0"+now;
			}
			else if(qry("1"+now))
			{
				now="1"+now;
			}
			else
			{
				n++;
				flag=false;
			}
		}
	}
	cout<<"! "<<now<<endl;
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
