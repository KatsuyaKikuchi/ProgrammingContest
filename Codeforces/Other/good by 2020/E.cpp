#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[65];

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> S(65, 0);
    REP(i, N) {
        REP(j, 65) {
            if ((A[i] >> j) & 1)
                S[j]++;
        }
    }
    ll ret = 0;
    REP(i, N) {
        ll x = 0;
        REP(b, 61) {
            if ((A[i] >> b) & 1) {
                x += ((N % MOD) * P[b] % MOD);
            }
            else {
                x += (S[b] % MOD) * P[b] % MOD;
            }
            x %= MOD;
        }
        REP(a, 61) {
            if (((A[i] >> a) & 1) == 0)
                continue;
            ret += (x * S[a] % MOD) * P[a] % MOD;
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    P[0] = 1;
    REP(i, 64) {
        P[i + 1] = P[i] * 2LL % MOD;
    }
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}