#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

//����O��n�����ĸ��Ӷȣ�����̰��˼�����������û���ܹ���һ������������������ϵģ����û���Ǿͻ��Լ� 

map<char,int> mp{
    {'A',0},
    {'C',1},
    {'G',2},
    {'T',3}
};

void solve()
{
	int n; cin>>n;
    string a,b; cin>>a>>b;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(mp[a[i]]+mp[b[i]]!=3){
            for(int j=i+1;j<n;j++){
                if(mp[a[i]]+mp[b[j]]==3&&mp[a[j]]+mp[b[i]]==3){
                    swap(b[i],b[j]);
                    break;
                }
            }
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

signed main()
{
	int t = 1;
	//cin>>t
	while(t--)
	{
		solve();
	}
	return 0;
}
