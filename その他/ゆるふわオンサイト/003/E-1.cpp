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
ll C[200005];
ll D[200005];
ll SA[200005];
ll SB[200005];
ll SC[200005];
ll SD[200005];

ll LM[200005];
ll RM[200005];

int main() {
    ll N;
    cin >> N;
    memset(SA, 0, sizeof(SA));
    memset(SB, 0, sizeof(SB));
    memset(SC, 0, sizeof(SC));
    memset(SD, 0, sizeof(SD));
    REP(i, N) {
        cin >> A[i];
        SA[i] += A[i];
        SA[i + 1] += SA[i];
    }
    REP(i, N) {
        cin >> B[i];
        SB[i] += B[i];
        SB[i + 1] += SB[i];
    }
    REP(i, N) {
        cin >> C[i];
        SC[i] += C[i];
        SC[i + 1] += SC[i];
    }
    REP(i, N) {
        cin >> D[i];
        SD[i] += D[i];
        SD[i + 1] += SD[i];
    }

    memset(LM, 0, sizeof(LM));
    memset(RM, 0, sizeof(RM));
    {
        LM[1] = A[0] + B[1];
        FOR(i, N, 2) {
            LM[i] = std::max({LM[i - 1] + B[i],
                              B[i] + SA[i - 1],
                              B[i] + B[i - 1] + SA[i - 2]});
        }
    }
    {
        RM[N - 2] = C[N - 2] + D[N - 1];
        for (ll i = N - 3; i >= 0; --i) {
            RM[i] = std::max({RM[i + 1] + C[i],
                              C[i] + SD[N - 1] - SD[i],
                              C[i] + C[i + 1] + SD[N - 1] - SD[i + 1]});
        }
    }

    ll ans = 0;
    FOR(i, N - 2, 1) {
        ans = std::max(ans, LM[i] + RM[i + 1]);
    }
    cout << ans << endl;
    return 0;
}