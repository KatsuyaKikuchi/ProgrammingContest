#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll solve() {
    ll N, P;
    cin >> N >> P;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    if (P == 1) {
        if (N % 2 == 0)
            return 0;
        return 1;
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll index = 0;
    ll mx = 0, mn = 0;
    while (index < N) {
        mx = modpow(P, A[index++]);
        ll x = 1;
        while (index < N) {
            REP(j, A[index - 1] - A[index]) {
                if (x > N)
                    break;
                x *= P;
            }
            mn += modpow(P, A[index++]);
            if (--x <= 0)
                break;
        }
        if (x == 0) {
            mx = 0;
            mn = 0;
        }
    }
    mn %= MOD;
    return (MOD + mx - mn) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}