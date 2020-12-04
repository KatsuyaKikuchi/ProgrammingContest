#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[1005];
ll C[1005];

ll modpow(ll n, ll m, ll p) {
    ll ret = 1;
    ll t = n;
    REP(i, 60) {
        if (((m >> i) & 1) == 1) {
            ret = (ret * t) % p;
        }
        t = (t * t) % p;
    }
    return ret % p;
}

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    REP(i, N) {
        A[i] %= M;
    }
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    REP(i, N) {
        REP(j, M) {
            if (A[i] - j >= 0)
                B[j] += C[A[i] - j];
            if (A[i] + M - j < M)
                B[j] += C[A[i] + M - j];
        }
        C[A[i]]++;
    }

    ll ans = 1;
    if (B[0] > 0)
        ans = 0;
    else {
        REP(i, M) {
            ans = (ans * modpow(i, B[i], M)) % M;
        }
    }
    cout << ans << endl;
    return 0;
}