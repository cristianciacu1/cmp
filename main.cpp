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
#include <queue>

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
    while (t--) {
        int n; cin >> n;
        ll largest_start = INT_MIN;
        ll smallest_end = INT_MAX;
        set<ll> r;

        for (int i = 0; i < n; ++i) {
            ll a, b;
            cin >> a >> b;

            if (a == 1) {
                largest_start = max(largest_start, b);
            }
            if (a == 2) {
                smallest_end = min(smallest_end, b);
            }
            if (a == 3) {
                r.insert(b);
            }
        }
        
        ll diff = smallest_end - largest_start + 1;

        if (diff < 0) { cout << "0\n"; continue; }

        if (r.size() < diff) {
            for (const auto& i: r) {
                if (i >= largest_start && i <= smallest_end) --diff;
            }
        } else {
            for (int i = largest_start; i <= smallest_end; ++i) {
                if (r.find(i) != r.end()) --diff;
            }
        }

        cout << diff << "\n";
    }
    return 0;
}