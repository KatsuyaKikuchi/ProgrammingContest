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

Vertex V[100005];
ll C[100005];
ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    REP(i, N) {
        C[i] = INF;
    }
    queue<pll> q;
    q.push(pll(0, 0));
    C[0] = 0;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = t.second;
        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i];
            if (C[n] <= cost)
                continue;
            C[n] = cost;
            A[n] = t.first + 1;
            q.push(pll(n, cost));
        }
    }
    REP(i, N) {
        if (C[i] == INF) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    REP(i, N - 1) {
        cout << A[i + 1] << endl;
    }
    return 0;
}