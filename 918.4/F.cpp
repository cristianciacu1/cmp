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

struct Job {
    long long a, b;

    Job(long long a_, long long b_) {
        a = a_;
        b = b_;
    }

    Job() {}

    bool operator < (const Job& j) const {
        return b < j.b;
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            int a, b; cin >> a >> b;
            jobs[i] = Job(a, b);
        }

        sort(jobs.begin(), jobs.end());

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (jobs[j].a >= jobs[i].a) ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}