#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> L(N, 0), R(N, 0);
    REP(i, X) {
        ll c;
        cin >> c;
        c--;
        L[c]++;
    }
    REP(i, Y) {
        ll c;
        cin >> c;
        c--;
        R[c]++;
    }

    REP(i, N) {
        ll m = std::min(L[i], R[i]);
        L[i] -= m;
        R[i] -= m;
    }
#if false
    REP(i, N) {
        cout << L[i] << " " << R[i] << endl;
    }
#endif
    ll cnt = abs(X - Y) / 2;
    //! R<->Lは最低限でいいはず
    ll ret = 0;
    if (X > Y) {
        REP(i, N) {
            ll m = std::min(cnt, L[i] / 2);
            ret += m;
            cnt -= m;
            L[i] -= 2 * m;
        }
        REP(i, N) {
            ret += R[i];
        }
    }
    else if (X < Y) {
        REP(i, N) {
            ll m = std::min(cnt, R[i] / 2);
            ret += m;
            cnt -= m;
            R[i] -= 2 * m;
        }
        REP(i, N) {
            ret += L[i];
        }
    }
    else {
        REP(i, N) {
            ret += L[i];
        }
    }
    ret += cnt * 2LL;

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