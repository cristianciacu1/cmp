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

    for (i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }

    if (n % i == 0) ans.push_back(i);
    ans.push_back(n);

    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        int min_num = INT_MAX;
        for (int i = 0; i < n; ++i) { cin >> v[i]; min_num = min(min_num, v[i]);}

        vector<int> divs = get_divs(n);
        int ans = 0;

        for (const auto& d : divs) {
            for (int i = 0; i < n / d; i+=d) {
                vector<int> mini_divs = get_divs(min_num);

                for (const int md : mini_divs) {
                    bool ok = true;
                    for (int j = i; j < i + d; ++j) {
                        if (v[i] % md != 0) {
                            ok = false; break;
                        }
                    }
                    if (ok) {
                        ans++;
                        break;
                    }
                }
            }
        } 
        cout << ans << "\n";
    }
    return 0;
}