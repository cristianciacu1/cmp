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
        int n, m; cin >> n >> m;

        vector<ll> a(n);
        vector<ll> b(m);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll l = min(n, m);
        ll ans = 0;

        ll start_a = 0, end_a = n - 1;
        ll start_b = 0, end_b = m - 1;

        for (int i = 0; i < l; ++i) {
            const ll diff1 = abs(a[start_a] - b[start_b]);
            const ll diff2 = abs(a[start_a] - b[end_b]);
            const ll diff3 = abs(a[end_a] - b[start_b]);
            const ll diff4 = abs(a[end_a] - b[end_b]);

            const ll diff_aux1 = max(diff1, diff2);
            const ll diff_aux2 = max(diff3, diff4);

            const ll diff_aux = max(diff_aux1, diff_aux2);

            if (diff_aux == diff1) {
                start_a++;
                start_b++;
            } else if (diff_aux == diff2) {
                start_a++;
                end_b--;
            } else if (diff_aux == diff3) {
                end_a--; start_b++;
            } else {
                end_a--; start_b++;
            }

            ans += diff_aux;

        } 

        cout << ans << "\n";
    }
    return 0;
}