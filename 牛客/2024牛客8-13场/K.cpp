#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (m == 1) {
        cout << *max_element(a.begin() + 1, a.end()) << "\n";
        return;
    }

    multiset<int, greater<>> s(a.begin() + 1, a.end());

    int ans = *max_element(a.begin() + 1, a.end());
    int cnt = 0;
    while (*s.begin() > 0) {
        auto t = *s.begin();
        s.erase(s.begin());
        s.insert(t / m);
        cnt++;
        ans = min(ans, *s.begin() + cnt);
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}
