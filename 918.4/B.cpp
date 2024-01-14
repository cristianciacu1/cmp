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
        for (int i = 0; i < 3; ++i) {
            int a[3] = {0};
            for (int j = 0; j < 3; ++j) {
                char b; cin >> b;
                if (b != '?')
                    a[b-'A'] = 1;
            }
            if (a[0] == 0) cout << "A" << "\n";
            if (a[1] == 0) cout << "B" << "\n";
            if (a[2] == 0) cout << "C" << "\n";
        }
    }
    return 0;
}