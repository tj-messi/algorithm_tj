#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int sx = n, ex = 0, sy = m, ey = 0;
    for (int i = 1; i <= n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		if (s[j] == 'x') {
    			sx = min(sx, i);
    			ex = max(ex, i);
    			sy = min(sy, j);
    			ey = max(ey, j);
    		}
    	}
    }

    int x = ex - sx + 1, y = ey - sy + 1;
    int d = __gcd(x, y);
    x /= d, y /= d;
    for (int i = 1; i <= x; i++) {
    	cout << string(y, 'x') << "\n";
    }

    return 0;
}
