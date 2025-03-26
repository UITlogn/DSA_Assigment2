#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 205;
int n, a[N];

void printA() {
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

void insertionSort() {
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            printA();
            j = j - 1;
        }

            a[j + 1] = key;
            printA();
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    insertionSort();
    return 0;
}