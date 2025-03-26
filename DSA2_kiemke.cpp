#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e6+5;
int n;
string a[N];

void quickSort(string a[], int l, int r) {
    string p = a[l + r >> 1];
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

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    quickSort(a, 1, n);

    int ans = 1;
    for (int i = 2; i <= n; ++i)
        ans += (a[i] != a[i - 1]);
    
    cout << ans;
    return 0;
}