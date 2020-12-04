#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

Vertex V[2005];
ll C[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X, Y;
    cin >> N >> X >> Y;
    REP(i, N - 1) {
        V[i].node.push_back(i + 1);
        V[i + 1].node.push_back(i);
    }
    X--;
    Y--;
    V[X].node.push_back(Y);
    V[Y].node.push_back(X);

    std::map<ll, ll> M;
    REP(i, N) {
        REP(j, N) {
            C[j] = INF;
        }
        C[i] = 0;
        queue<pll> q;
        q.push(pll(i, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(j, V[t.first].node.size()) {
                ll n = V[t.first].node[j];
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
                if (n > i)
                    M[cost]++;
            }
        }
    }

    REP(i, N - 1) {
        cout << M[i + 1] << endl;
    }
    return 0;
}