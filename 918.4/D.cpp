// https://codeforces.com/problemset/problem/1675/C
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace::std;

vector<long long> res(31, -1);
long long power(int base, int pow) {
    if (pow == 0) return 1;
    if (pow == 1) return base;
    
    if (res[pow] != -1) return res[pow];

    long long jum = power(base, pow / 2);

    if (pow % 2) {
        return jum * jum * base;
    } else {
        return jum * jum;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s; cin.get();

        vector<vector<char> > ans;
    
        for (int i = s.length() - 1; i >= 0; --i) {
            vector<char> curr;
            if (s[i] == 'b' || s[i] == 'c' || s[i] == 'd') {
                curr.push_back(s[i]);
                curr.push_back(s[i-1]);
                curr.push_back(s[i-2]);
                i-=2;
            } else {
                curr.push_back(s[i]);
                curr.push_back(s[i-1]);
                i--;
            }
            ans.push_back(curr);
        }

        for (int i = ans.size() - 1; i >= 0; --i) {
            for (int j = ans[i].size() - 1; j >= 0; --j) {
                cout << ans[i][j];
            }
            if (i != 0) cout << ".";
        }
        cout << "\n";
    }
    return 0;
}