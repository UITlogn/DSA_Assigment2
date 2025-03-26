#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e5+5;
int n, a[N], b[N];
int s[N];
map<int, int> pos;

int calc() {
    pos.clear();
    for (int i = 1; i <= n; ++i) {
        pos[s[i]] = i;
        a[i] = b[i];
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        while (a[i] != s[i]) {
            int j = pos[a[i]];
            swap(a[i], a[j]);
            ++res;
        }
    }
    return res;
}
int calc1() {
    sort(s + 1, s + n + 1);
    return calc();
}
int calc2() {
    sort(s + 1, s + n + 1, greater<int>());
    return calc();
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        if (++pos[a[i]] > 1) {
            for (int j = 1; j < 1e9; ++j);
        }
        s[i] = a[i];
    }

    int ans1 = calc1();
    int ans2 = calc2();
    // cout << ans1 << ' ' << ans2 << '\n';
    cout << min(ans1, ans2);
    return 0;
}