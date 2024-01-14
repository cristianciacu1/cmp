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

    if (n % 2 == 1) { cout << "0\n"; return 0; } 

    ll biggest = 1;
    int steps = 0;
    while (biggest < n) {
        biggest *= 2;
        ++steps;
    }
    if (biggest == n) {
        cout << steps << "\n";
    } else {
        --steps;
        biggest /= 2;

        while (n != biggest) {
            if (biggest < n)
                n -= biggest;
            --steps;
            biggest /= 2;
        }

        cout << steps << "\n";
    }
    return 0;
}