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

string S[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> S[i];
    }

    atcoder::mcf_graph<ll, ll> g(N * M + 2);
    ll s = N * M, t = N * M + 1;
    ll offset = 0;
    REP(i, N) {
        REP(j, M) {
            if (S[i][j] == '#')
                continue;
            ll v = i * M + j;
            if (S[i][j] == 'o') {
                g.add_edge(s, v, 1, 0);
                offset += INF - (i + j);
            }
            g.add_edge(v, t, 1, INF - (i + j));
            if (i < N - 1) {
                ll nxt = (i + 1) * M + j;
                g.add_edge(v, nxt, INF, 0);
            }
            if (j < M - 1) {
                ll nxt = i * M + j + 1;
                g.add_edge(v, nxt, INF, 0);
            }
        }
    }

    cout << -(g.flow(s, t).second - offset) << endl;

    return 0;
}