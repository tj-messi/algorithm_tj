#include<bits/stdc++.h>
using namespace std;
#define int long long

auto sqrt_128 = [](__int128 x) -> __int128 {
    int L = 0, R = 1e17;

    while (L < R) {
        __int128 mid = L + R + 1 >> 1;
        if (mid * mid <= x) {
            L = mid;
        } else {
            R = mid - 1;
        }
    }

    return L;
};//二分开根号 

auto print = [](__int128 x) {
    vector<int> t;
    while (x) {
        t.push_back(x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    for (auto & x : t) {
        cout << x;
    }
};//输出 

void QAQ() {
    int n;
    cin >> n;

    n /= 2;

    string l, r;
    cin >> l >> r;


    auto F = [&](string & r) {
        __int128 mx = 0, cnt = 1, tt = 0;
        for (int i = 0; i < n; i++) {
            mx *= 10;
            mx += r[i] - '0';
            cnt *= 10;
        }
        for (int i = n; i < r.size(); i++) {
            tt *= 10;
            tt += r[i] - '0';
        }

        cnt--;

        __int128 l = sqrt_128(mx), un = sqrt_128(cnt);
        if (l * l == mx) {
            return l * (un + 1) + sqrt_128(tt) + 1;
        } else {
            return (l + 1) * (un + 1);
        }
    };

    auto get = [&](string & r) -> __int128 {
        __int128 mx = 0, tt = 0;
        for (int i = 0; i < n; i++) {
            mx *= 10;
            mx += r[i] - '0';
        }

        for (int i = n; i < r.size(); i++) {
            tt *= 10;
            tt += r[i] - '0';
        }

        __int128 ll = sqrt_128(mx), un = sqrt_128(tt);
        if (ll * ll == mx && un * un == tt) {
            return 1;
        } else {
            return 0;
        }
    };

    print(F(r) - F(l) + get(l));
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}
