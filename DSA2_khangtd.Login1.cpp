#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e6+5, MOD = 1e9+7, BASE = 257;

int gethash(const string &s) {
    int n = s.size();
    int h = 0;
    for (int i = 1; i <= n; ++i)
        h = (h * BASE %MOD + s[i-1]) %MOD;
    return h;
}

string s, t;
map<int, string> mp;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, q; cin >> n >> q;
    while (n--) {
        cin >> s >> t;
        int h = gethash(s);
        mp[h] = t;
    }

    while (q--) {
        cin >> s;
        int h = gethash(s);
        if (mp.count(h)) cout << mp[h];
        else cout << "Chua Dang Ky!";
        cout << '\n';
    }
    return 0;
}