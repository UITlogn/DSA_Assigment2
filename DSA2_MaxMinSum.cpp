#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e5+5, MOD = 1e9+7;
int n, k, a[N];

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
int f[N], g[N];
int C(int k, int n) {
    if (k > n) return 0;
    return f[n] * g[k] % MOD * g[n-k] % MOD;
}
void prepare() {
    f[0] = g[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i-1] * i % MOD;
    g[N-1] = Pow(f[N-1], MOD-2, MOD);
    for (int i = N-2; i > 0; --i)
        g[i] = g[i+1] * (i+1) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    prepare();
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    
    for (int i = 1; i <= n; ++i) {
        a[i] += MOD;
        a[i] %= MOD;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // a[i] sẽ là phần tử lớn nhất trong các cách chọn k phần tử từ i phần tử đầu mà có chứa a[i]
        ans += a[i] * C(k - 1, i - 1) % MOD;
        // a[i] sẽ là phần tử nhỏ nhất trong các cách chọn k phần tử từ (n - i + 1) phần tử cuối mà có chứa a[i]
        ans -= a[i] * C(k - 1, n - i) % MOD;

        ans += MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}