#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    REP(i, N) {
        cin >> S[i];
    }

    atcoder::mf_graph<ll> g(N * M + 2);
    ll s = N * M, t = N * M + 1;

    //! グリッドグラフは2部グラフ
    //! odd gridに入り even gridから出るフローを考える
    REP(i, N) {
        REP(j, M) {
            if (S[i][j] == '#')
                continue;
            ll v = i * M + j;
            if ((i + j) % 2 == 0) {
                g.add_edge(s, v, 1);
                REP(n, 4) {
                    ll nx = x[n] + i, ny = y[n] + j;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if (S[nx][ny] == '#')
                        continue;
                    ll u = nx * M + ny;
                    g.add_edge(v, u, 1);
                }
            }
            else
                g.add_edge(v, t, 1);
        }
    }

    cout << g.flow(s, t) << endl;
    auto edges = g.edges();
    for (auto &e:edges) {
        if (e.to == t || e.from == s || e.flow == 0)
            continue;
        ll i0 = e.from / M, j0 = e.from % M;
        ll i1 = e.to / M, j1 = e.to % M;
        if (i0 + 1 == i1) {
            S[i0][j0] = 'v';
            S[i1][j1] = '^';
        }
        else if (i0 == i1 + 1) {
            S[i0][j0] = '^';
            S[i1][j1] = 'v';
        }
        else if (j0 + 1 == j1) {
            S[i0][j0] = '>';
            S[i1][j1] = '<';
        }
        else if (j0 == j1 + 1) {
            S[i0][j0] = '<';
            S[i1][j1] = '>';
        }
    }
    REP(i, N) {
        REP(j, M) {
            cout << S[i][j];
        }
        cout << endl;
    }

    return 0;
}