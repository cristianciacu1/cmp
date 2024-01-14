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

// ((3 + 2) * (4 + 5)) = 45
// split("((3 + 2) * (4 + 5))") -> ["(3 + 2)", "*", "(4 + 5)"]

// target: 24, numbers: [1, 2, 3, 4]
// possible expression: ((3 * 4) * (2 * 1))

bool distinct(int n) {
    set<int> s;
    while (n) {
        if (s.find(n % 10) != s.end()) return false;
        s.insert(n % 10);
        n /= 10;
    }
    return true;
}

string userAndId(string s) {
    bool num[51] = {false};
    num[s.length() - 1] = true;    
    for (int i = s.length() - 2; i >= 0; --i) {
        if (s[i] >= '0' && s[i] <= '9' && num[i+1] == true) {
            num[i] = true;
        } else num[i] = false;
    }

    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        if (num[i] == true && s[i] != '0') {
            return ans;
        }
        ans += s[i];
    }
    return ans;
}

const int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(vector<vector<char> >& v, vector<vector<bool> >& visited, int i, int j, string& curr, string& ans) {
    if (curr.length() == 3) {
        if (curr.compare(ans) < 0) {
            ans = curr;
        }
        return;
    }

    visited[i][j] = true;

    for (int k = 0; k < 8; ++k) {
        const int i1 = i + di[k];
        const int j1 = j + dj[k];

        if (i1 >= 0 && i1 < 3 && j1 >= 0 && j1 < 3) {
            if (!visited[i1][j1]) {
                curr.push_back(v[i1][j1]);
                dfs(v, visited, i1, j1, curr, ans);
                curr.pop_back();
            }
        }
    }
}

vector<long long> res(31, -1);
long long power(int base, int pow) {
    if (pow == 0) return 1;
    if (pow == 1) return base;
    
    if (res[pow] != -1) return res[pow];

    long long jum = power(base, pow / 2);

    if (pow % 2) {
        return jum * jum * base;
    } else {
        return jum * jum;
    }
}

bool insideCircle(double ax, double ay, double bx, double by, double radius) {
    const double d = sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));
    return 0 < d && d <= 2 * radius;
}

class Solution {
public:
    struct Job {
        int start, end, profit;

        Job(int start_, int end_, int profit_) {
            start = start_;
            end = end_;
            profit = profit_;
        }

        bool operator <(const Job& j2) const {
            return start < j2.start;
        }
    };

    int next(vector<Job>& jobs, int start_index, int prev_end) {
        for (int i = start_index + 1; i < jobs.size(); ++i) {
            if (jobs[i].start >= prev_end) return i;
        }
        return -1;
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;

        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(startTime.size() + 1, 0);

        for (int i = startTime.size() - 1; i >= 0; --i) {
            int nextAvailable = next(jobs, i, jobs[i].end);
            nextAvailable = (nextAvailable == -1) ? 0 : dp[nextAvailable];

            const int pick = jobs[i].profit + nextAvailable;

            dp[i] = max(pick, (i + 1 < profit.size()) ? dp[i+1] : 0);
        }
        
        return dp[0];
    }
};

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
        ll n, x, k;
        cin >> n >> x >> k;

        vector<Node> nodes;
        vector<Edge> edges;

        for (ll i = 0; i <= n; ++i) {
            nodes.push_back(Node(i));
        }

        for (ll i = 2; i <= n; ++i) {
            nodes[i].n.push_back(nodes[i / 2]);
            nodes[i / 2].n.push_back(nodes[i]);

            // cout << nodes[i].id << " " << nodes[i / 2].id << "\n";
        }

        queue<pair<Node, ll> > q;
        q.push(make_pair(nodes[x], 0));

        ll ans = 0;
        set<ll> visited;

        while (!q.empty()) {
            const pair<Node, ll> curr = q.front();
            q.pop();
            visited.insert(curr.first.id);

            if (curr.second == k) {
                ans++;
                continue;
            }

            for (const Node& node: curr.first.n) {
                if (visited.find(node.id) == visited.end()) {
                    q.push(make_pair(node, curr.second + 1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}