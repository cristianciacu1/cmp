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

vector<int> get_divs(int n) {
    vector<int> ans;
    int i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }

    if (n % i == 0) ans.push_back(i);

    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        string a1, b1;

        for (int i = 0; i < n; ++i) {
            char x; cin >> x;
            a[i] = x - '0';
        }

        for (int i = 0; i < n; ++i) {
            char x; cin >> x;
            b[i] = x - '0';
        }

        int zero_instead_of_1 = 0;
        int one_instead_of_0 = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 1 && b[i] == 0) {
                zero_instead_of_1++;
            }
            if (a[i] == 0 && b[i] == 1) {
                one_instead_of_0++;
            }
        }

        ll ans = 0;

        while (zero_instead_of_1 > 0 && one_instead_of_0 > 0) {
            ans++; --zero_instead_of_1; --one_instead_of_0;
        }

        ans += zero_instead_of_1 + one_instead_of_0;

        cout << ans << "\n";
    }
    return 0;
}