#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

ll modpow(ll n, ll p, ll mod) {
    ll ret = 1;
    ll r = n;
    while (p > 0) {
        if ((p & 1) == 1)
            ret = (ret * r) % mod;
        r = r * r % mod;
        p >>= 1;
    }
    return ret;
}

ll calc(ll x) {
    ll ret = 0;
    while (x % 2 == 0) {
        ret++;
        x /= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }

    ll m = calc(A[0]);
    REP(i, N) {
        if (m != calc(A[i])) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll p = 1;
    ll r = 1;
    REP(i, N) {
        r = r / gcd(r, A[i] / 2) * A[i] / 2;
        p = p / gcd(p, A[i]) * A[i];

        if (p > M)
            p = M;
        if (r > M) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (M - r) / p + 1 << endl;

    return 0;
}