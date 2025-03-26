#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

string s;
int cnt[10];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.ans", "w", stdout);
    }

    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }
    sort(s.begin(), s.end(), greater<char>());

    if (sum % 3 == 0) return cout << s, 0;

    string ans = "0";
    for (int i = 0; i < s.size(); ++i) {
        string t = s;
        t.erase(i, 1);
        if ((sum - s[i] + '0') % 3 == 0)
            ans = max(ans, t);

        for (int j = 0; j < t.size(); ++j) {
            string r = t;
            r.erase(j, 1);
            if ((sum - s[i] + '0' - t[j] + '0') % 3 == 0)
                ans = max(ans, r);
        }
    }

    cout << ans;
    return 0;
}