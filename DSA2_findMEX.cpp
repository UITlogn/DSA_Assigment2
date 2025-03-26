#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e6+5;

int a[N];

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

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    quickSort(a, 1, n);

    int mex = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > mex)
            return cout << mex, 0;
        if (a[i] == mex) ++mex;
    }
    cout << mex;
    return 0;
}