#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 2e5+5;
int a[N];
int n;
bool check(int num)
{
	int temp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=num)
		{
			temp+=a[i]-num;
		}
		else
		{
			if(temp>0)
			{
				temp=max(0ll,temp+a[i]-num);
			}
		}
	}
	if(temp==0)
		return 1;
	else
		return 0;
}

bool check0(int num)
{
	int rem = 0;
	for (int i = n ; i >= 1; --i)
	{
		if (a[i] <= num)
		{
			rem += num - a[i];
		}
		else
		{
			rem = max(0ll, rem - (a[i] - num));
		}
	}
	if (rem == 0)
		return 1;
	else
		return 0;
}


void solve()
{
	cin>>n;
	int max_num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		max_num=max(max_num,a[i]);
	}
	int l=0,r=max_num;
	int min_maxnum=max_num;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid-1;
			min_maxnum=min(min_maxnum,mid);
		}
		else
		{
			l=mid+1;
		}
	}
	int top=min_maxnum;
	int temp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=top)
		{
			temp+=a[i]-top;
			a[i]=top;
		}
		else
		{
			if(temp>=(top-a[i]))
			{
				temp-=(top-a[i]);
				a[i]=top;
			}
			else
			{
				a[i]+=temp;temp=0;
			}
			
		}
	}
	l=0;r=top;
	int max_minnum=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check0(mid))
		{
			l=mid+1;
			max_minnum=max(max_minnum,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	int down=max_minnum;
	//cout<<top<<" "<<down<<endl;
	cout<<top-down<<endl;
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
