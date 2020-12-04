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

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % mod;
        p = (p * p) % mod;
        r /= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll P, N;
    cin >> P >> N;
    REP(i, N) {
        cin >> A[i];
    }
    string S;
    cin >> S;

    ll ans = A[0];
    REP(i, S.length()) {
        ll n = A[i + 1];
        if (S[i] == '+') {
            ans = (ans + n) % P;
        }
        else if (S[i] == '-') {
            ans = (P + ans - n) % P;
        }
        else if (S[i] == '*') {
            ans = (ans * n) % P;
        }
        else {
            ans = (ans * modpow(n, P - 2, P)) % P;
        }
    }
    cout << ans << endl;
    return 0;
}