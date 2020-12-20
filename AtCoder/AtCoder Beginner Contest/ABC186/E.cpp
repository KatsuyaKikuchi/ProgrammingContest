#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll solve() {
    ll N, S, K;
    cin >> N >> S >> K;
    ll d = N - S;
    ll x = K % N;
    if (x == 0) {
        return -1;
    }
    ll g = gcd(x, N);
    if (g == 1) {
        ll X, Y;
        ll p = extGCD(x, N, X, Y);
        ll t = d * X;
        if (t < 0) {
            return N - (abs(t) % N);
        }
        else {
            return t % N;
        }
    }
    else {
        if (d % g == 0) {
            ll X, Y;
            ll p = extGCD(x / g, N / g, X, Y);
            ll t = d * X;
            ll y;
            if (t < 0) {
                y = (N - (abs(t) % N)) % N;
            }
            else {
                y = t % N;
            }

            ll ans = y;
            ll n = N / g;
            //cout << n << endl;
            return ans / g;
        }
        else {
            return -1;
        }
    }
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