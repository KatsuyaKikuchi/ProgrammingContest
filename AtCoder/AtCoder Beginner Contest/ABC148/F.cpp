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
ll T[100005];
ll A[100005];

int main() {
    ll N, u, v;
    cin >> N >> u >> v;
    u--;
    v--;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    {
        memset(A, -1, sizeof(A));
        A[v] = 0;
        queue<pll> q;
        q.push(pll(v, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                if (A[n] >= 0)
                    continue;
                A[n] = t.second + 1;
                q.push(pll(n, t.second + 1));
            }
        }
    }

    ll max = 0;
    {
        memset(T, -1, sizeof(T));
        T[u] = 0;
        queue<pll> q;
        q.push(pll(u, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (V[t.first].node.size() > 1) {
                max = std::max(max, A[t.first]);
            }
            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                if (T[n] >= 0)
                    continue;
                T[n] = t.second + 1;
                if (T[n] <= A[n])
                    q.push(pll(n, t.second + 1));
            }
        }
    }

    cout << max << endl;
    return 0;
}