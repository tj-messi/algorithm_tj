#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
字典树trie
通过像树一样构建子节点来简化查询前缀的过程
比如三串字符abc,abd,abed;
可以建成如下的字典树trie
a-b-e-d
   -c
   -d 
此时ab前缀就是3次 
*/
const int N = 1e3+5;
int idx=0;//各个节点的位置
int son[N][26];//字典树
int cnt[N];//标记某个编号结尾的单词 

void insert(string s)
{
	int p=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		int u=s[i]-'a';//映射
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
		int u=s[i]-'a';
		if(!son[p][u])return 0;
		p=son[p][u];
	}
	return cnt[p];
}

void solve()
{
	string s1="abc";
	string s2="abc";
	string s3="abc";
	insert(s1);
	insert(s2);
	insert(s3);
	cout<<query("a")<<endl;
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
