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

#define ll long long

using namespace::std;

struct Node {
    ll id;
    vector<Node> n;

    Node(ll id_) {
        id = id_;
    }

    Node() {}
};

struct Edge {
    Node a, b;

    Edge(Node a_, Node b_) {
        a = a_;
        b = b_;
    }
};

struct Graph {
    vector<Node> nodes;
    vector<Edge> edges;
};

int main() {
    int t; cin >> t;
    vector<int> anss;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n == 1) { cout << "0\n"; continue; } 

        sort(a.begin(), a.end());

        int s1 = 0, s2 = 0;
        int ans = INT_MIN;

        for (int i = 0; i < n - x; ++i) s1 += a[i];
        for (int i = n - x; i < n; ++i) s2 -= a[i];

        int j1 = n - x - 1, j2 = n - 1;

        while (j2 >= n - k) {
            ans = max(ans, s1 + s2);
            if (j1 >= 0) {
                s1 -= a[j1];
                s2 -= a[j1];
            }
            s2 += a[j2];
            --j1, --j2;
        }
        ans = max(ans, s1 + s2);

        // cout << ans << "\n";

        anss.push_back(ans);
    }
    for (int i = 0; i < anss.size(); ++i) cout << anss[i] << endl;
    return 0;
}