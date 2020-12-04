#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(ll x, ll s, ll t) {
    return abs(x - s) + abs(s - t);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> S(1, -INF), T(1, -INF);
    REP(i, A) {
        ll s;
        cin >> s;
        S.push_back(s);
    }
    REP(i, B) {
        ll t;
        cin >> t;
        T.push_back(t);
    }
    S.push_back(INF);
    T.push_back(INF);

    REP(i, Q) {
        ll x;
        cin >> x;
        auto s0 = lower_bound(S.begin(), S.end(), x);
        auto t0 = lower_bound(T.begin(), T.end(), x);
        auto s1 = s0--;
        auto t1 = t0--;

        ll ans = std::min({calc(x, *s0, *t0), calc(x, *t0, *s0), calc(x, *s1, *t0), calc(x, *t0, *s1),
                           calc(x, *s0, *t1), calc(x, *t1, *s0), calc(x, *s1, *t1), calc(x, *t1, *s1)});

        cout << ans << endl;
    }
    return 0;
}