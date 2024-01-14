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
    ll n; cin >> n;

    ll ans = 0;

    ll num = 0;
    int x = n;
    while (x > 0) {
        num++; x /= 10;
    }

    for (ll i = 1; i <= min(n, 9 * num + 2); ++i) {
        ll sum = 0;
        ll j = i;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        if (i % sum == 0) { ans++; cout << i << "\n"; }
    }

    cout << ans << "\n";

    return 0;
}