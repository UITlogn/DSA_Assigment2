#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 205;
int n, a[N];

void printA() {
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

void bubbleSort() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                printA();
            }
        }
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

    bubbleSort();
    return 0;
}