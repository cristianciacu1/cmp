// https://codeforces.com/problemset/problem/1903/B
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <fstream>
#include <vector>

using namespace::std;

bool distinct(int n) {
    set<int> s;
    while (n) {
        if (s.find(n % 10) != s.end()) return false;
        s.insert(n % 10);
        n /= 10;
    }
    return true;
}

string userAndId(string s) {
    bool num[51] = {false};
    num[s.length() - 1] = true;    
    for (int i = s.length() - 2; i >= 0; --i) {
        if (s[i] >= '0' && s[i] <= '9' && num[i+1] == true) {
            num[i] = true;
        } else num[i] = false;
    }

    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        if (num[i] == true && s[i] != '0') {
            return ans;
        }
        ans += s[i];
    }
    return ans;
}

const int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(vector<vector<char> >& v, vector<vector<bool> >& visited, int i, int j, string& curr, string& ans) {
    if (curr.length() == 3) {
        if (curr.compare(ans) < 0) {
            ans = curr;
        }
        return;
    }

    visited[i][j] = true;

    for (int k = 0; k < 8; ++k) {
        const int i1 = i + di[k];
        const int j1 = j + dj[k];

        if (i1 >= 0 && i1 < 3 && j1 >= 0 && j1 < 3) {
            if (!visited[i1][j1]) {
                curr.push_back(v[i1][j1]);
                dfs(v, visited, i1, j1, curr, ans);
                curr.pop_back();
            }
        }
    }
}

int main() {
    // 000 011 011 101
    // 011 000 011 111
    // 011 011 000 111
    // 101 111 111 000

    // M[i][j] = a[i] | a[j]

    // M[0][1] = a[0] | a[1] = M[1][0]
    // M[0][2] = a[0] | a[2] = M[2][0]
    // M[0][3] = a[0] | a[3] = M[3][0]

    // M[1][2] = a[1] | a[2] = M[2][1]
    // M[1][3] = a[1] | a[3] = M[3][1]

    // M[2][3] = a[2] | a[3] = M[3][2]

    // a[0]: 001
    // a[1]: 011
    // a[2]: 011
    // a[3]: 100

    // and operation

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int> > v(n, vector<int>(n, 0));
        vector<int> max_per_row(n, INT_MIN);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x; cin >> x;
                v[i][j] = x;
                max_per_row[i] = max(max_per_row[i], v[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int a = max_per_row[i];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                a = a & v[i][j];
            }
            ans.push_back(a);
        }
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            for (int j = 0; j < n && ok; ++j) {
                if (i != j && v[i][j] != (ans[i] | ans[j])) {
                    ok = false;
                    cout << "NO\n";
                    break;
                }
            }
        }

        if (!ok) continue;

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
