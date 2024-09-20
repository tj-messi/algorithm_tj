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
	bool flag=false;
	while(n--)
	{
		if(!flag)
		{
			if(qry(now+"0"))//now+0ÊÇ 
			{
				now=now+"0";continue;
			}
			else if(qry(now+"1"))//now+1ÊÇ 
			{
				now=now+"1";continue;
			}
			else
			{
				n++;
				flag=true;
				continue;
			}
		}
		else
		{
			if(qry("0"+now))
			{
				now="0"+now;continue;
			}
			else
			{
				now="1"+now;continue;
			}
		}
	}
	cout<<"! "<<now<<endl;
}

signed main()
{
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	//t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
