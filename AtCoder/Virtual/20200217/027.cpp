#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll G[3][3];
ll B[2][3];
ll C[3][2];

pll calc(vector<ll> v) {
    memset(G, 0, sizeof(G));
    REP(i, v.size()) {
        ll h = v[i] / 3, w = v[i] % 3;
        G[h][w] = i % 2;
    }
    pll p(0, 0);
    REP(i, 2) {
        REP(j, 3) {
            if (G[i][j] == G[i + 1][j])
                p.first += B[i][j];
            else
                p.second += B[i][j];
        }
    }
    REP(i, 3) {
        REP(j, 2) {
            if (G[i][j] == G[i][j + 1])
                p.first += C[i][j];
            else
                p.second += C[i][j];
        }
    }
    return p;
}

pll solve(vector<ll> v) {
    if (v.size() == 9) {
        return calc(v);
    }
    pll p(-1, -1);
    REP(i, 9) {
        bool e = false;
        REP(j, v.size()) {
            if (v[j] == i)
                e = true;
        }
        if (e)
            continue;
        v.push_back(i);
        pll t = solve(v);
        v.pop_back();
        if (v.size() % 2 == 0) {
            if (p.first < t.first)
                p = t;
        }
        else {
            if (p.second < t.second)
                p = t;
        }
    }
    return p;
}

int main() {
    REP(i, 2) {
        REP(j, 3) {
            cin >> B[i][j];
        }
    }
    REP(i, 3) {
        REP(j, 2) {
            cin >> C[i][j];
        }
    }

    vector<ll> v;
    pll p = solve(v);
    cout << p.first << endl;
    cout << p.second << endl;
    return 0;
}