#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e5+5;
int MOD;

int Pow(int a, int b, int M) {
    a %= M;
    if (b == 0) return 1;
    if (b == 1) return a %M;
    int t = 1;
    while (b) {
        if (b & 1) t = t*a %M;
        a = a*a %M;
        b >>= 1;
    }
    return t;
}

const int N = 1e5+5;
int par[N], rak[N];
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        rak[i] = 0;
    }
}
int find(int u) {
    if (par[u] != u) par[u] = find(par[u]);
    return par[u];
}
bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    if (rak[u] == rak[v]) ++rak[u];
    if (rak[u] < rak[v]) par[u] = v;
    else par[v] = u;
    return 1;
}

void getRepresentation(int n, vector<int> &res) {
    while (n > 0) {
        res.push_back(n % MOD);
        n /= MOD;
    }
}
int f[N], g[N];
int C(int k, int n) {
    if (k > n) return 0;
    return f[n] * g[k] % MOD * g[n-k] % MOD;
}
int nCr(int k, int n) {
    vector<int> x, y;
    x.clear(); y.clear();
    getRepresentation(n, x);
    getRepresentation(k, y);
    int res = 1;
    for (int i = 0; i < y.size(); ++i) {
        res *= C(y[i], x[i]);
        res %= MOD;
    }
    return res;
}
void prepare() {
    f[0] = g[0] = 1;
    for (int i = 1; i < MOD; ++i)
        f[i] = f[i-1] * i % MOD;
    g[MOD-1] = Pow(f[MOD-1], MOD-2, MOD);
    for (int i = MOD-2; i > 0; --i)
        g[i] = g[i+1] * (i+1) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t >> MOD;
    prepare();
    while (t--) {
        int n; cin >> n;
        int ans = nCr(n, n * 2 - 1);
        cout << ans << '\n';
    }
    return 0;
}