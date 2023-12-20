// https://codeforces.com/problemset/problem/1899/C
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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v.push_back(x);
        }
        
        int even = (v[0] % 2 == 0 ? 0 : -1);
        int odd = (v[0] % 2 == 1 ? 0 : -1);
        bool prev_odd = (v[0] % 2 ? true : false);
        int sum = v[0];
        int max_sum = v[0];
        // cout << sum << " ";

        for (int i = 1; i < n; ++i) {
            max_sum = max(max_sum, sum);
            bool isOdd = (v[i] % 2 == 1 || v[i] % 2 == -1);
            if (prev_odd == isOdd) {
                sum = v[i];
            } else {
                prev_odd = !prev_odd;
                if (sum + v[i] < v[i]) {
                    sum = v[i];
                } else {
                    sum += v[i];
                }
            }
        }
        max_sum = max(max_sum, sum);

        cout << max_sum << endl;
    }

    return 0;
}
