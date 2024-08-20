#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

//复杂度o(n+m) 
const int N =1e3+5;
int nexta[N];

void getnext(string modstr)
{
	int i=0;int j=-1;
	nexta[0]=-1;
	int mlen=modstr.size();
	while(i<mlen-1)
	{
		if(j==-1||modstr[i]==modstr[j])
		{
			i++;j++;
			nexta[i]=j;
		}
		else
		{
			j=nexta[j];
		}
	}
}
//把目标串种的第一个modelstr找出来，如果没有返回-1； 
int kmp(string dststr,string modelstr)
{
	int i=0;int j=0;
	int dstlen=dststr.size();
	int modellen=modelstr.size();
	while(i<dstlen&&j<modellen)
	{
		if(j==-1||dststr[i]==modelstr[j])
		{
			j++;i++;
		}
		else j=nexta[j];
	}
	if(j>=modellen)
	{
		return i-modellen;
	}
	else return -1;
}

void solve()
{
	string a="abbababacd";
	string b="bacd";
	getnext(b);
	cout<<kmp(a,b);
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
