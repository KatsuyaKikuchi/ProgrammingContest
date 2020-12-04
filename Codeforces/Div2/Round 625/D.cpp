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

Vertex V[200005];
Vertex RV[200005];
ll C[200005];
ll P[200005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        RV[b].node.push_back(a);
    }

    ll K;
    cin >> K;
    REP(i, K) {
        cin >> P[i];
        P[i]--;
    }
    REP(i, N) {
        C[i] = INF;
    }
    C[P[K - 1]] = 0;
    {
        queue<pll> q;
        q.push(pll(P[K - 1], 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(i, RV[t.first].node.size()) {
                ll n = RV[t.first].node[i];
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }

    ll min = 0, max = 0;
    {
        REP(i, K - 1) {
            ll p = P[i];
            ll n = P[i + 1];
            ll pc = C[p];
            ll nc = C[n];
            if (pc - 1 == nc) {
                ll m = 0;
                REP(j, V[p].node.size()) {
                    ll a = V[p].node[j];
                    if (C[a] == nc)
                        m++;
                }
                if (m > 1)
                    max++;
            }
            else {
                min++;
            }
        }
    }

    cout << min << " " << max + min << endl;

    return 0;
}