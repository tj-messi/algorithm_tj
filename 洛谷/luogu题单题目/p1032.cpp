#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

string a,b;					
string sa[8],sb[8];			
map<string,int> map1;		//��֦ 
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
			s=q.front();				//��S��ֵΪ��ǰҪ�������ַ���
			while (1)					//�ҳ��Ӵ�sa[i]������λ��
			{	
				m=s.find(sa[i]);		//��S������Ӵ�sa[i]�ĵ�һ�γ���λ��
				if (m==-1) break;		//���ȫ�ҳ���(�Ҳ���)��,�ͽ���ѭ��
				ss=q.front();			//��SS��ֵΪ��ǰҪ�������ַ���
				ss.replace(m,sa[i].size(),sb[i]);	//��SS�����Ӵ�sb[i]�滻��S���һ�γ��ֵ��Ӵ�sa[i]
				q.push(ss);				//��ת�����SSѹ�����
				bb.push(bb.front()+1);	//��ת�����SS�Ѿ�ʹ�õĲ���ѹ�����
				s[m]='~';				//��S���Ӵ�sa[i]�ĵ�һ�γ���λ����㻻����һ���޹ص��ַ�,�����Ϳ��Բ��ҵ�S���Ӵ�sa[i]����һ������λ��
			}
			
			
		}
		q.pop();						//�����������ַ�����������
		bb.pop();						//���������ַ����Ѿ��ù��Ĳ���һ�鵯��
	}
	if (q.empty()==1||bb.front()>10) return -1;//û���ٽ��п���,���߳�������,�ͷ���-1
		else return bb.front();					//����,�����ҵ���,�㷵������ʹ�ò���
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
