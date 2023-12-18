#include <iostream>
#include <set>
#include <unordered_map>
#include <math.h>

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
    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n; cin.get();
        int siz = n;
        unordered_map<char, int> m;
        int max_occ = INT_MIN;
        while (n--) {
            char c; cin.get(c);
            m[c]++;
            max_occ = max(max_occ, m[c]);
        }
        cin.get();

        if (max_occ >= ceil(siz / 2.0)) {
            cout << 2 * max_occ - siz << "\n";
            continue;
        }
        if (siz % 2 == 0) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}