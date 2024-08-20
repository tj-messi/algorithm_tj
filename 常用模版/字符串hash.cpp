#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
字符串hash: 
用哈希的思想将每一个字符串转化成一串“id”
id有可能相同，这就是哈希碰撞 
*/
const int N = 1e6+10;
const int P = 131;//经验证明这个131质数配合ull自然溢出很难被hash碰撞 
int h[N],p[N];

ull strhash(int l,int r)
{
	return h[r]-h[l-1]*p[r-l+1];
}

void solve()
{
	string str="abcdennnabcde";
	str=" "+str;
	p[0]=1;
	for(int i=1;i<=str.size()-1;i++)
	{
		p[i]=p[i-1]*P;
		h[i]=h[i-1]*P+str[i];
	}
	if(strhash(2,5)==strhash(10,13))
		cout<<"Same"<<endl;
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
