#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        cin >> C[i];
        C[i]--;
    }
    vector<ll> p(N);
    REP(i, N) {
        p[i] = i;
    }
    vector<vector<ll>> v(N);
    vector<map<ll, ll>> m(N);
    REP(i, N) {
        v[i].push_back(i);
        m[i][C[i]]++;
    }

    REP(_, Q) {
        ll t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            if (p[a] == p[b])
                continue;
            ll x = p[a];
            ll y = p[b];
            if (v[x].size() > v[y].size()) {
                //! y->x
                REP(i, v[y].size()) {
                    ll n = v[y][i];
                    v[x].push_back(n);
                    p[n] = x;
                    m[x][C[n]]++;
                }
                v[y].clear();
            }
            else {
                REP(i, v[x].size()) {
                    ll n = v[x][i];
                    v[y].push_back(n);
                    p[n] = y;
                    m[y][C[n]]++;
                }
                v[x].clear();
            }
        }
        else {
            ll x = p[a];
            cout << m[x][b] << endl;
        }
    }

    return 0;
}