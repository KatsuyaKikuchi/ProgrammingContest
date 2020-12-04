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
ll B[200005];
ll S[200005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    sort(A, A + N);
    sort(B, B + M);
    memset(S, 0, sizeof(S));

    for (ll i = N - 1; i >= 0; --i) {
        S[i] += S[i + 1];
        ll ok = M, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (B[mid] > A[i])
                ok = mid;
            else
                ng = mid;
        }
        S[i] += M - ok;
    }

    ll ans = 0;
    REP(i, N - 1) {
        ll low = -1, ng = M - 1;
        while (abs(low - ng) > 1) {
            ll mid = (low + ng) / 2;
            if (B[mid] < A[i])
                low = mid;
            else
                ng = mid;
        }

        ll t = (low + 1) * S[i + 1] % MOD;
        ans = (ans + t) % MOD;
    }
    cout << ans << endl;
    return 0;
}