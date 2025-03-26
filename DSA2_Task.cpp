#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, k, p, q; cin >> n >> k >> p >> q;

    int id1 = (p - 1) * 2 + q;
    // id1 % k == id2 % k
    int id2 = id1 + k;
    int x = -1, y = -1;
    if (id2 <= n) {
        x = (id2 + 1) / 2, y = (id2 + 1) % 2 + 1;

    }

    int id3 = id1 - k;
    if (id3 >= 1) {
        int u = (id3 + 1) / 2, v = (id3 + 1) % 2 + 1;
        if (x == -1 || abs(u - p) + abs(v - q) < abs(x - p) + abs(y - q))
            x = u, y = v;
    }

    if (x == -1) return cout << -1, 0;
    cout << x << ' ' << y;
    return 0;
}