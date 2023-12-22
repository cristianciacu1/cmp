// https://codeforces.com/problemset/problem/1894/B
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
        vector<int> v;
        unordered_map<int, vector<int> > m;
        int ok1 = -1, ok2 = -1;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v.push_back(x);
            m[x].push_back(i);
            if (m[x].size() >= 2) {
                if (ok1 == -1) ok1 = x;
                else if (ok2 == -1 && x != ok1) ok2 = x;
            }
        }
        if (ok1 == -1 || ok2 == -1) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> ans(v.size(), 1);

        bool option1 = false;
        bool option2 = false;
        
        for (const auto& x : m) {
            if (option1 && option2) break;

            int key = x.first;
            vector<int> indices = x.second;

            if (indices.size() >= 2) {
                if (!option1) {
                    option1 = true;
                    ans[indices[0]] = 1;
                    ans[indices[1]] = 2;
                } else {
                    if (!option2) {
                        option2 = true;
                        ans[indices[0]] = 1;
                        ans[indices[1]] = 3;
                    }
                }
            }
        }

        for (const auto& x : ans) {
            cout << x << " ";
        }
        cout << "\n";


    }

    return 0;
}
