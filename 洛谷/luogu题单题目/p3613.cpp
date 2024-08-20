#include<cstdio>
#include<map>
using namespace std;
int n,q,p,k;
map<long long,int>b;
long long i,j;
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d%d",&p,&i,&j);
		if(p==1)
		{
			scanf("%d",&k);
			b[i*1000000+j]=k;
		}
		else printf("%d\n",b[i*1000000+j]);
	}
	return 0;
}
