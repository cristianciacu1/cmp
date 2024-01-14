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
#include <map>

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

        vector<long long> a(n);
        long long s = 0;

        map<long long, bool> m;
        bool ok = false;
        m[0] = true;

        for (int i = 0; i < n; ++i) cin >> a[i];

        for (int i = 0; i < n; ++i) {
            a[i] *= (i % 2 == 0) ? 1 : -1;
            s += a[i];

            if (m[s]) {
                cout << "YES\n";
                ok = true;
                break;
            }

            m[s] = true;
        }   

        if (!ok) cout << "NO\n";
    }
    return 0;
}