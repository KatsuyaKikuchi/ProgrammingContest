#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
ll P[200005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    ll N, X, D;
    cin >> N >> X >> D;

    if (D == 0) {
        if (X == 0)
            cout << 1 << endl;
        else
            cout << N << endl;
        return 0;
    }
    else if (X == 0) {
        ll n = (N - 1) * N / 2;
        cout << n / 2 + 1 << endl;
        return 0;
    }

    P[0] = P[1] = 0;
    FOR(i, N, 1) {
        P[i + 1] = P[i] + i;
    }

    ll g = gcd(abs(X), abs(D));
    if (g == 1) {
        ll s = 0;
        ll n = (N - 1) * N / 2;
        REP(i, N + 1) {
            ll d0 = n - P[i];
            ll d1 = P[N - i] - 2 * (P[i]);

            ll k = abs(d0 - d1) / 2;
            cout << k << endl;
            s += k;
        }
        cout << s << endl;
        return 0;
    }

    return 0;
}