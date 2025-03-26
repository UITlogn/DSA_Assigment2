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

void selectionSort() {
    for (int i = 1; i <= n; ++i) {
        int pos = i;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < a[pos]) {
                pos = j; 
            }
        }
        if (pos != i) {
            swap(a[i], a[pos]);
            printA();
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

    selectionSort();
    return 0;
}