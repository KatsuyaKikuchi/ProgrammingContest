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
    vector<pll> node;
};

Vertex V[100005];
ll A[100005];
bool U[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        V[a].node.push_back(pll(b, w));
        V[b].node.push_back(pll(a, w));
    }

    memset(A, 0, sizeof(A));
    memset(U, 0, sizeof(U));
    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        U[t.first] = true;
        REP(i, V[t.first].node.size()) {
            pll n = V[t.first].node[i];
            if (U[n.first])
                continue;
            ll cost = n.second + t.second;
            A[n.first] = cost % 2;
            q.push(pll(n.first, cost));
        }
    }

    REP(i, N) {
        cout << A[i] << endl;
    }
    return 0;
}