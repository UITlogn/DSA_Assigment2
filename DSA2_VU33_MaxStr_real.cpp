#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

string s;
int cnt[10];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
        ++cnt[s[i] - '0'];
    }
    sort(s.begin(), s.end(), greater<char>());

    if (sum % 3 == 0) return cout << s, 0;

    // tạo SỐ lớn nhất:
    // for (int i = sum % 3; i <= 9; i += 3)
    //     if (cnt[i]) {
    //         --cnt[i];
    //         sum = 0;
    //         break;
    //     }
    
    // if (sum != 0) {
    //     for (int i = 3 - sum % 3, check = 0; i <= 9; i += 3)
    //         while (cnt[i]) {
    //             --cnt[i];
    //             if (++check == 2)
    //                 break;
    //         }
    // }

    // tạo XÂU lớn nhất
    int last = 0;
    for (int i = 1; i <= 9; ++i) {
        if (i % 3 == sum % 3) {
            if (cnt[i]) {
                --cnt[i];
                break;
            }
        } 
        else if (i % 3 != 0) {
            if (cnt[i]) {
                if (last != 0) {
                    --cnt[i], --cnt[last];
                    break;
                }
                if (cnt[i] > 1) {
                    cnt[i] -= 2;
                    break;
                }
                last = i;
            }
        }
    }

    for (int i = 9; i >= 0; --i) {
        while (cnt[i]--) cout << char('0' + i);
    }

    return 0;
}