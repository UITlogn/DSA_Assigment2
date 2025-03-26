#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second

const int N = 1e5+5;
int n, k, a[N];

vector<II> b;

void quickSort(int a[], int l, int r) {
    int p = a[l + r >> 1];
    int i = l, j = r;
    while (i < j) {
        while (a[i] < p) ++i;
        while (p < a[j]) --j;

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (i < r) quickSort(a, i, r);
    if (l < j) quickSort(a, l, j);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    quickSort(a, 1, n);

    for (int i = 1, cnt = 1; i <= n; ++i, ++cnt) {
        if (i == n || a[i] != a[i + 1]) {
            b.push_back(II(a[i], cnt));
            cnt = 0;
        }
    }

    k = n - k;

    for (II &i: b) {
        // cout << i.fi << ' ' << i.se << '\n';
        if (i.se > 1) {
            if (i.se - 1 <= k) {
                k -= i.se - 1;
                i.se = 1;
            } else {
                i.se -= k;
                k = 0;
            }
        }
        if (k == 0) break;
    }

    while (k > 0) {
        b.pop_back();
        --k;
    }
    
    for (II i: b) {
        while (i.se--) cout << i.fi << ' ';
    }

    return 0;
}