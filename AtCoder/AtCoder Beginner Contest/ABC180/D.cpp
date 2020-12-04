#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 4e18;
ll T = (ll) 1e9;

ll X, Y, A, B;

bool check(ll m) {
    ll x = X;
    while (m > 0) {
        if (x >= B || A >= B) {
            //! B選ぶ
            ll y = Y - 1 - x;
            m -= y / B;
            break;
        }

        ll t = x * (A - 1);
        if (t >= B) {
            //! B選ぶ
            ll y = Y - 1 - x;
            m -= y / B;
            break;
        }
        x = x * A;
        if (x >= Y)
            break;
        --m;
    }

    return m <= 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> X >> Y >> A >> B;
    ll ok = 0, ng = INF;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}