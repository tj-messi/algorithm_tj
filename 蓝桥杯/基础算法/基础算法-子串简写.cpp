#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

//满足O（n方）的复杂度，根据贪心思想就优先找有没有能够换一次能满足两个都配对上的，如果没有那就换自己 

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
