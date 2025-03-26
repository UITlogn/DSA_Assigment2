#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e6+5, MOD = 1e9+7, BASE = 257;
int p[N], h[N];

int gethash(int l, int r) {
    return (h[r] - (h[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

string s, t;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] * BASE) % MOD;
    h[0] = 0;
    for (int i = 1; i <= n; ++i)
        h[i] = (h[i - 1] * BASE % MOD + s[i - 1]) % MOD;

    int ht = 0;
    for (int i = 1; i <= m; ++i)
        ht = (ht * BASE % MOD + t[i - 1]) % MOD;

    int ans = 0;
    vector<int> pos;
    for (int i = 1; i + m - 1 <= n; ++i) {
        if (gethash(i, i + m - 1) == ht) {
            ++ans;
            pos.push_back(i);
        }
    }
    if (pos.size() == 0) return cout << "NO", 0;
    cout << "YES\n";
    for (int i: pos) cout << i << ' ';
    return 0;
}