#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    string v, u;
    ll n;
};
struct Vertex {
    vector<pll> node;
    string s;
};

Data D[205];
bool U[405];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<string> S;

    //! mが小数の場合や1の場合などに問題があるかも？
    REP(i, N) {
        cin >> D[i].v >> D[i].n >> D[i].u;
        S.push_back(D[i].u);
        S.push_back(D[i].v);
    }

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    vector<Vertex> V(S.size());
    REP(i, N) {
        ll v = lower_bound(S.begin(), S.end(), D[i].v) - S.begin();
        ll u = lower_bound(S.begin(), S.end(), D[i].u) - S.begin();
        V[v].node.push_back(pll(u, D[i].n));
        V[v].s = D[i].v;
        V[u].s = D[i].u;
    }

    Data ans;
    ans.n = 0;
    memset(U, 0, sizeof(U));
    REP(i, S.size()) {
        queue<pll> q;
        q.push(pll(i, 1));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (t.second > ans.n) {
                ans.n = t.second;
                ans.v = S[i];
                ans.u = S[t.first];
            }
            REP(j, V[t.first].node.size()) {
                pll nxt = V[t.first].node[j];
                ll cost = t.second * nxt.second;
                ll n = nxt.first;
                q.push(pll(n, cost));
            }
        }
    }
    cout << "1" << ans.v << "=" << ans.n << ans.u << endl;
    return 0;
}