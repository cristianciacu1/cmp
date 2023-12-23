// https://codeforces.com/problemset/problem/1891/B
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
        int n, m; cin >> n >> m;
        vector<long long> a(n, 0);
        vector<long long> x(m, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<long long> arr;

        // Key to success
        for (int i = 0; i < m; ++i) {
            cin >> x[i];
            if (arr.empty() || arr.back() > x[i]) {
                arr.push_back(x[i]);
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            long long b = power(2, arr[i]);
            long long c = power(2, arr[i] - 1);

            for (int j = 0; j < n; ++j) {
                if (a[j] % b == 0) {
                    a[j] += c;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        
    }

    return 0;
}
