// https://codeforces.com/problemset/problem/1899/B
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>

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
        vector<long long> v(n, 0);
        vector<long long> sum_left(n, 0);
        for (int i = 0; i < n; ++i) {
            long long x; cin >> x;
            v[i] = x;
            if (i == 0) sum_left[0] = v[i];
            else sum_left[i] = sum_left[i-1] + v[i];
        }

        long long ans = LLONG_MIN;

        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                vector<long long> currs;
                long long minimum = LLONG_MAX, maximum = LLONG_MIN;
                for (int j = i - 1; j < n; j += i) {
                    long long curr_sum;
                    if (j == 0) curr_sum = v[0];
                    else curr_sum = sum_left[j] - (j - i >= 0 ? sum_left[j - i] : 0);
                    minimum = min(minimum, curr_sum);
                    maximum = max(maximum, curr_sum);
                }
                ans = max(ans, abs(maximum - minimum));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
