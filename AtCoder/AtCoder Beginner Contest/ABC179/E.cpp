#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[100005];
ll P[100005];

ll func(ll a, ll m) {
    return a * a % m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X, M;
    cin >> N >> X >> M;
    N--;

    memset(P, 0, sizeof(P));
    memset(T, -1, sizeof(T));
    P[X]++;
    T[X] = 0;

    REP(i, N) {
        X = func(X, M);
        if (T[X] < 0) {
            T[X] = i + 1;
            P[X]++;
            continue;
        }

        //! ループを始める
        ll x = i + 1 - T[X];
        ll n = N - i;
        REP(j, x) {
            ll p = n / x;
            if (n % x > j)
                p++;
            P[X] += p;
            X = func(X, M);
        }
        break;
    }

    ll ans = 0;
    REP(i, M) {
        ans += i * P[i];
    }

    cout << ans << endl;

    return 0;
}