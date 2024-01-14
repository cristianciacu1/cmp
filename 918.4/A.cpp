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
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) cout << c << "\n";
        if (a == c) cout << b << "\n";
        if (b == c) cout << a << "\n";
    }
    return 0;
}