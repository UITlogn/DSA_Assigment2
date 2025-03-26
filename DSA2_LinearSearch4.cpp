#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second

const int N = 1e5+5;

map<int, int> cnt;

bool solve() {
    int n, k; cin >> n >> k;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }

    int cnt1 = 0; // số số xuất hiện 1 lần
    int cnt2 = 0; // số số xuất hiện >=2 lần

    for (II x: cnt) {
        if (x.se == 1) ++cnt1;
        else ++cnt2;
    }
    // cout << cnt1 << ' ' << cnt2 << ' ';

    if (cnt1 + cnt2 * 2 < k * 2) return 0;

    if (cnt1 + cnt2 > k * 2) return 0;
    return 1;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}