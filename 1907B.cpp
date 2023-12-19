// https://codeforces.com/problemset/problem/1907/B
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

int main() {
    ofstream g("data.out");
    int t; cin >> t; cin.get();
    string s;

    while (t--) {
        cin >> s; cin.get();
        vector<pair<char, int> > v;
        vector<pair<char, int> > V;
        int i = 0;
        for (int k = 0; k < s.length(); ++k) {
            if (s[k] == 'b') {
                if (!v.empty()) {
                    v.pop_back();
                }
            } else {
                if (s[k] == 'B') {
                    if (!V.empty()) {
                        V.pop_back();
                    }
                } else if (s[k] >= 'a' && s[k] <= 'z') {
                    v.push_back(make_pair(s[k], i++));
                } else {
                    V.push_back(make_pair(s[k], i++));
                }
            }
        }

        string ans = "";

        i = 0;
        int j = 0;

        while (i < v.size() && j < V.size()) {
            pair<char, int> low = v[i];
            pair<char, int> high = V[j];

            if (low.second < high.second) {
                ans += low.first;
                ++i;
            } else {
                ans += high.first;
                ++j;
            }
        }

        while (i < v.size()) {
            ans += v[i].first;
            ++i;
        }

        while (j < V.size()) {
            ans += V[j].first;
            ++j;
        }

        cout << ans << "\n";
    }
    return 0;
}
