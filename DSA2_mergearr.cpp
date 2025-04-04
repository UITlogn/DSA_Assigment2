
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int a[], int n, int b[], int m, int c[]) {
    int j = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && b[j] < a[i]) c[k++] = b[j++];
        c[k++] = a[i];
    }
    while (j < m) c[k++] = b[j++];
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}