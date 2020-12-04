#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char C[4] = {'N', 'S', 'E', 'W'};
ll x[4] = {0, 0, 1, -1};
ll y[4] = {1, -1, 0, 0};

ll solve() {
    string S;
    cin >> S;
    pll g(0, 0);
    map<tuple<pll, pll>, bool> m;
    ll N = S.length();
    ll ret = 0;
    REP(i, N) {
        REP(j, 4) {
            if (C[j] == S[i]) {
                ll nx = g.first + x[j];
                ll ny = g.second + y[j];
                pll nxt = pll(nx, ny);
                auto t = make_tuple(std::min(g, nxt), std::max(g, nxt));
                if (m[t])
                    ret++;
                else
                    ret += 5LL;
                m[t] = true;
                g = nxt;
                break;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}