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

const int dj[3] = {-1, 0, 1};

void play(int n, int m, int a_i, int a_j, int b_i, int b_j, set<string>& results, bool alice_turn) {
    if (results.size() > 1) return;

    if (a_i == n - 1 || b_i == 0) {
        results.insert("Draw");
        return;
    }
    
    if (alice_turn) {
        for (int i = 0; i < 3; ++i) {
            const int a_new_i = a_i + 1;
            const int a_new_j = a_j + dj[i];

            if (a_new_i < 0 || a_new_i >= n || a_new_j < 0 || a_new_j >= m) continue;

            if (a_new_i == b_i && a_new_j == b_j) {
                results.insert("Alice");
                continue;
            }

            play(n, m, a_new_i, a_new_j, b_i, b_j, results, !alice_turn);
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            const int b_new_i = b_i - 1;
            const int b_new_j = b_j + dj[i];

            if (b_new_i < 0 || b_new_i >= n || b_new_j < 0 || b_new_j >= m) continue;

            if (b_new_i == a_i && b_new_j == a_j) {
                results.insert("Bob");
                continue;
            }

            play(n, m, a_i, b_j, b_new_i, b_new_j, results, !alice_turn);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, a_i, a_j, b_i, b_j;
        cin >> n >> m >> a_i >> a_j >> b_i >> b_j;
        a_i--;
        a_j--;
        b_i--;
        b_j--;
        set<string> results;
        bool alice_turn = true;

        play(n, m, a_i, a_j, b_i, b_j, results, alice_turn);

        // cout << results.size() << "\n";

        if (results.size() == 2 && results.find("Draw") != results.end()) {
            if (results.find("Alice") != results.end()) cout << "Alice\n";
            if (results.find("Bob") != results.end()) cout << "Bob\n";
        } else if (results.size() > 1) {
            cout << "Draw\n";
        } else if (results.size() == 1) {
            for (const auto& s : results) {
                cout << s << "\n";
            }
        }

    }
    return 0;
}