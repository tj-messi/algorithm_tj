#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

string a,b;					
string sa[8],sb[8];			
map<string,int> map1;		//剪枝 
int l;						
queue<string> q;			
queue<int> bb;			
int bfs()
{
	int i,j,k,m,n;
	string s,ss;
	while (q.empty()==0&&q.front()!=b&&bb.front()<=10)		
	{
		if (map1[q.front()]==1) 	
		{
			q.pop();
			bb.pop();
			continue;
		}
		map1[q.front()]=1;			
		for (i=1;i<=l;i++)			
		{	
			s=q.front();				//将S赋值为当前要操作的字符串
			while (1)					//找出子串sa[i]的所有位置
			{	
				m=s.find(sa[i]);		//在S里查找子串sa[i]的第一次出现位置
				if (m==-1) break;		//如果全找出来(找不到)了,就结束循环
				ss=q.front();			//将SS赋值为当前要操作的字符串
				ss.replace(m,sa[i].size(),sb[i]);	//在SS中用子串sb[i]替换掉S里第一次出现的子串sa[i]
				q.push(ss);				//将转换后的SS压入队列
				bb.push(bb.front()+1);	//将转换后的SS已经使用的步数压入队列
				s[m]='~';				//将S里子串sa[i]的第一次出现位置随便换成另一种无关的字符,这样就可以查找到S里子串sa[i]的下一个出现位置
			}
			
			
		}
		q.pop();						//将操作过的字符串弹出队列
		bb.pop();						//操作过的字符串已经用过的步数一块弹出
	}
	if (q.empty()==1||bb.front()>10) return -1;//没法再进行宽搜,或者超出步数,就返回-1
		else return bb.front();					//否则,就是找到了,便返回最少使用步数
}

void solve()
{
	int i,j,k,m,n;
	cin>>a>>b;							
	l=1;
	while (cin>>sa[l]>>sb[l]) l++;		
	l--;								
	if (l==0&&a!=b)						
	{
		cout<<"NO ANSWER!";
		return;
	}
	q.push(a);						
	bb.push(0);						
	k=bfs();						
	if (k==-1)						
	{
		cout<<"NO ANSWER!";
		return;
	}
	cout<<k;		
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
