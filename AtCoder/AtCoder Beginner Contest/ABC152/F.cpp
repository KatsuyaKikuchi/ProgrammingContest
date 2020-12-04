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

Vertex V[55];
pll T[25];
vector<ll> E[25];
bool U[25];
ll S[25];

int main() {
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(pll(b, i));
        V[b].node.push_back(pll(a, i));
    }
    ll M;
    cin >> M;
    REP(i, M) {
        cin >> T[i].first >> T[i].second;
        T[i].first--;
        T[i].second--;
        U[i] = true;
    }

    REP(i, M) {
        ll s = T[i].first;
        ll g = T[i].second;
        vector<ll> C(N, INF);
        C[s] = 0;
        queue<pll> q;
        q.push(pll(s, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(j, V[t.first].node.size()) {
                ll n = V[t.first].node[j].first;
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
        while (g != s) {
            REP(j, V[g].node.size()) {
                pll n = V[g].node[j];
                if (C[n.first] == C[g] - 1) {
                    g = n.first;
                    E[i].push_back(n.second);
                    break;
                }
            }
        }
    }

    //! 被覆区間の解消
    REP(i, M) {
        vector<bool> u(N - 1, false);
        REP(j, E[i].size()) {
            u[E[i][j]] = true;
        }
        REP(j, M) {
            if (i == j)
                continue;
            if (!U[j])
                continue;
            bool cover = true;
            REP(k, E[j].size()) {
                cover &= u[E[j][k]];
            }
            if (cover) {
                U[i] = false;
                break;
            }
        }
    }

    vector<ll> e;
    REP(i, M) {
        if (U[i])
            e.push_back(i);
    }

    REP(i, pow(2, e.size())) {
        ll m = 0;
        vector<bool> u(N - 1, true);
        REP(j, e.size()) {
            if ((i >> j) & 1) {
                m++;
                REP(k, E[e[j]].size()) {
                    u[E[e[j]][k]] = false;
                }
            }
        }
        ll t = 0;
        REP(j, N - 1) {
            if (u[j])
                t++;
        }
        S[m] += pow(2LL, t);
    }

    ll ans = 0;
    REP(i, e.size() + 1) {
        ll s = S[i];
        if (i % 2 == 1)
            s *= -1LL;
        ans += s;
    }
    cout << ans << endl;
    return 0;
}