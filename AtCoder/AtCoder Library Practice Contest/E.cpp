#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

ll A[55][55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
            A[i][j] = INF - A[i][j];
        }
    }

    atcoder::mcf_graph<ll, ll> g(N + N + 2);
    ll s = 2 * N, t = 2 * N + 1;
    g.add_edge(s, t, N * K, INF);
    REP(i, N) {
        g.add_edge(s, i, K, 0);
        g.add_edge(N + i, t, K, 0);
    }
    REP(i, N) {
        REP(j, N) {
            g.add_edge(i, N + j, 1, A[i][j]);
        }
    }

    vector<string> S(N);
    REP(i, N) {
        REP(j, N) {
            S[i].push_back('.');
        }
    }
    g.flow(s, t, N * K);
    ll ans = 0;
    auto edges = g.edges();
    for (auto &e : edges) {
        if (e.from == s || e.to == t || e.flow == 0)
            continue;
        ll i = e.from;
        ll j = e.to - N;
        S[i][j] = 'X';
        ans += INF - A[i][j];
    }

    cout << ans << endl;
    REP(i, N) {
        cout << S[i] << endl;
    }

    return 0;
}