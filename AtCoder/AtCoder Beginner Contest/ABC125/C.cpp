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
ll L[100005];
ll R[100005];

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    L[0] = A[0];
    FOR(i, N, 1) {
        L[i] = gcd(L[i - 1], A[i]);
    }
    R[N - 1] = A[N - 1];
    for (ll i = N - 2; i >= 0; --i) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    ll ans = std::max(R[1], L[N - 2]);
    for (ll i = 1; i < N - 1; ++i) {
        ans = std::max(ans, gcd(L[i - 1], R[i + 1]));
    }
    cout << ans << endl;
    return 0;
}