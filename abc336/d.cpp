// not solved during the contest.
// solution was inspired from the editorial.
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
#include <climits>

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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> l(n), r(n);
    l[0] = min(v[0], 1);
    r[n - 1] = min(v[n - 1], 1);

    for (int i = 1; i < n; ++i) {
        l[i] = min(v[i], l[i - 1] + 1);
    }

    for (int i = n - 2; i >= 0; --i) {
        r[i] = min(v[i], r[i + 1] + 1);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) ans = max(ans, min(l[i], r[i]));

    cout << ans << "\n";
    return 0;
}