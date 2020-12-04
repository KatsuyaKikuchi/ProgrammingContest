#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    ll ret = 0;

    REP(x, 20) {
        vector<ll> v;
        ll mn = INF;
        REP(i, N) {
            if (S[i] == T[i])
                continue;
            ll s = S[i] - 'a';
            if (s != x)
                continue;
            ll t = T[i] - 'a';
            if (s > t)
                return -1;
            mn = std::min(mn, t);
            v.push_back(i);
        }

        if (v.size() > 0) {
            ret++;
            REP(i, v.size()) {
                S[v[i]] = (char) (mn + 'a');
            }
        }
    }

    REP(i, N) {
        if (S[i] != T[i])
            return -1;
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