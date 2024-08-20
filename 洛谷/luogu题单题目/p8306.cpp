#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


const int N = 3e6+5;
int idx=0;//各个节点的位置
int son[N][65];//字典树
int cnt[N];//标记某个编号结尾的单词 

int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
} 

void insert(string s)
{
	int p=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		int u=getnum(s[i]);//映射
		if(!son[p][u])son[p][u]=++idx;
		p=son[p][u];
		cnt[p]++;
	}	
	
} 

int query(string s)
{
	int p=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		int u=getnum(s[i]);
		if(!son[p][u])return 0;
		p=son[p][u];
	}
	return cnt[p];
}

void solve()
{
	 for(int i=0;i<=idx;i++)
            for(int j=0;j<=65-1;j++)
                son[i][j]=0;
    for(int i=0;i<=idx;i++)
        cnt[i]=0;
    idx=0;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;insert(s);
	}
	for(int i=1;i<=m;i++)
	{
		string s;cin>>s;
		cout<<query(s)<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
