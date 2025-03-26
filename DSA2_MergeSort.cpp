#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 50;
int n, a[N];

void merge(int a[], int l, int mid, int r) {
    sort(a + l, a + r + 1);
}
void mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = l + r >> 1;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
        for (int i = 1; i < l; ++i) cout << a[i] << ' ';
        cout << "[ ";
        for (int i = l; i <= r; ++i) cout << a[i] << ' ';
        cout << "] ";
        for (int i = r + 1; i <= n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    mergesort(a, 1, n);
    return 0;
}