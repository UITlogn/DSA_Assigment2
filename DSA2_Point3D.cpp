#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e6+5;

struct node {
    int x, y, z;
    bool operator < (const node &u) {
        if (x == u.x) {
            if (y == u.y)
                return z < u.z;
            return y > u.y;
        }
        return x < u.x;
    }
} a[N];

void quickSort(node a[], int l, int r) {
    node p = a[l + r >> 1];
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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    quickSort(a, 1, n);

    for (int i = 1; i <= n; ++i) {
        cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
    }
    return 0;
}