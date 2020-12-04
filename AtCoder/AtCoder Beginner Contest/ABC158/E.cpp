#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 2019;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll p, ll mod) {
    ll ret = 1;
    ll r = n;
    while (p > 0) {
        if ((p & 1) == 1) {
            ret = ret * r % mod;
        }
        r = r * r % mod;
        p >>= 1;
    }
    return ret;
}

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    A[0] = 1;
    REP(i, N + 1) {
        A[i + 1] = (A[i] * 10) % P;
    }

    ll sum = 0;
    ll ans = 0;
    map<ll, ll> m;
    m[0]++;
    REP(i, N) {
        ll p = modpow(A[i], P - 2, P);
        sum = (sum * 10LL + S[i] - '0') % P;
        ll t = sum * p % P;
        if (P == 2) {
            if ((S[i] - '0') % 2 == 0)
                ans += i + 1;
        }
        else if (P == 5) {
            if ((S[i] - '0') % 5 == 0)
                ans += i + 1;
        }
        else {
            ans += m[t];
        }

        m[t]++;
    }
    cout << ans << endl;
    return 0;
}