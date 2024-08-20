#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
��״���飺
��o(logn)�ķ������� (�����޸�+�����ѯ)or(�����޸�+�����ѯ) 
*/
const int N = 5e5+5;
int n,m;
int a[N];
int diff[N];
int tree[N];//��״���� 
int lowbit(int x)
{
	return x&-x;	
}

void add(int x,int p)//������״���� 
{
	for(int i=x;i<=n;i+=lowbit(i))tree[i]+=p;
}

int sum(int x)//�õ�ǰ1~x������� 
{
	int res=0;
	for(int i=x;i>=1;i-=lowbit(i))res+=tree[i];
	return res;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		diff[i]=a[i]-a[i-1];
		add(i,diff[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x,y,k;cin>>x>>y>>k; 
			add(x,k);
			add(y+1,-k);
		}
		else
		{
			int x;cin>>x;
			cout<<sum(x)<<endl;
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
/*
#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


��״���飺
��o(logn)�ķ������� 

const int N = 5e5+5;
int n,m;
int a[N];
int tree[N];//��״���� 
int lowbit(int x)
{
	return x&-x;	
}

void add(int x,int p)//������״���� 
{
	for(int i=x;i<=n;i+=lowbit(i))tree[i]+=p;
}

int sum(int x)//�õ�ǰ1~x������� 
{
	int res=0;
	for(int i=x;i>=1;i-=lowbit(i))res+=tree[i];
	return res;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		add(i,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y;cin>>op>>x>>y;
		if(op==1)
		{
			add(x,y);
		}
		else
		{
			cout<<sum(y)-sum(x-1)<<endl;
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
*/
