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
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long x; cin >> x; sum += x;
        }
        if (sqrt(sum) == (int)sqrt(sum)) {
            cout << "YES\n"; 
        } else cout << "NO\n";
    }
    return 0;
}