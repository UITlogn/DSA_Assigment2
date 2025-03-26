#include <iostream>                                                                                                                                                                                      //Logm
#include <vector>
using namespace std;

const int N = 2e5+5, M = 205;
int n, k, a[N];
 
int bit[M];
void update(int i, int val) {
    ++i;
    for (; i < M; i += i & -i) bit[i] += val;
}
int get(int i) {
    ++i;
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

double med() {
    int l = 1, r = M - 1, x = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (get(mid) >= ((k + 1) >> 1)) {
            x = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    if (k % 2 == 1) return x * 2;

    l = 1, r = M - 1; int y = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (get(mid) > (k >> 1)) {
            y = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return x + y;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; ++i) {
        update(a[i], 1);
    }

    int ans = 0;
    for (int i = k + 1; i <= n; ++i) {
        int m = med();
        // cout << m << ' ';
        if (a[i] >= m) ++ans;

        update(a[i], 1);
        update(a[i - k], -1);
    }

    cout << ans;

    return 0;
}