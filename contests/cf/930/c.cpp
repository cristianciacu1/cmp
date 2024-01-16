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
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        int since_when_is_on = 0;

        for (int i = 0; i < n && f > 0; ++i) {
            const ll have_it_turned_on = (v[i] - since_when_is_on) * a;
            const ll have_it_closed = b;
            if (have_it_closed < have_it_turned_on) {
                f -= have_it_closed;
                since_when_is_on = v[i];
            } else {
                f -= have_it_turned_on;
            }
        }

        if (f <= 0) cout << "NO\n";
        else cout << "YES\n";

    }
    return 0;
}