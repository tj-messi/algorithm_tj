#include<bits/stdc++.h>  
using namespace std;  
#define int long long  
#define double long double  
#define endl '\n'  
  
const int N = 1e5 + 5;  
struct c{  
    int x, y;  
};  
c C[N];

void solve() 
{  
    int n;  
    cin >> n;  
     
    for (int i = 0; i < n; i++) {  
        cin >> C[i].x >> C[i].y;  
    }  
    int sx,sy,tx,ty;  
    cin >> sx >> sy >> tx >> ty;  
      
    int s = (tx-sx)*(tx-sx)+(ty-sy)*(ty-sy);
    int flag=true;
    for(int i=0;i<n;i++)
    {
    	if((C[i].x-tx)*(C[i].x-tx)+(C[i].y-ty)*(C[i].y-ty)-s<=0)
    		flag=false;
	}
    
    if (flag) {  
        cout << "YES" << endl;  
    } else {  
        cout << "NO" << endl;  
    }  
}  
  
signed main() {  
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    int t;  
    cin >> t;  
    while (t--) {  
        solve();  
    }  
    return 0;
}
