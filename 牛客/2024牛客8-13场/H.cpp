#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point {
	double x, y;
};
double cross(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
void solve() {
	int n;
	cin >> n;

	vector<point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	int m;
	cin >> m;

	vector<point> b(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
	}
	b[m] = b[0];

	double d = 0;
	for (int i = 0, j = 1; i < m; i++) {
		while (fabs(cross(b[i], b[i + 1], b[j])) <= fabs(cross(b[i], b[i + 1], b[(j + 1) % m]))) j = (j + 1) % m;
		d = max(d, hypot(b[i].x - b[j].x, b[i].y - b[j].y));
		d = max(d, hypot(b[i + 1].x - b[j].x, b[i + 1].y - b[j].y));
	}
	// cout << d << "\n";

	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += hypot(a[i].x - a[(i + 1) % n].x, a[i].y - a[(i + 1) % n].y);
	}

	cout << fixed << setprecision(12) << ans + acos(-1) * 2 * d << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
