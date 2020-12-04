#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[40005];
ll B[40005];

ll SB[40005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    memset(SB, 0, sizeof(SB));

    {
        ll s = 0;
        REP(i, M) {
            if (B[i] == 0)
                s = 0;
            else
                s++;
            SB[s]++;
        }
        for (ll i = M - 1; i >= 0; --i) {
            SB[i] += SB[i + 1];
        }
    }

    ll ans = 0;
    {
        for (ll h = 1; h <= N; ++h) {
            if (K % h > 0)
                continue;
            ll w = K / h;
            if (h > N || w > M)
                continue;

            ll sh = 0;
            REP(i, h) {
                sh += A[i];
            }

            if (sh == h)
                ans += SB[w];
            FOR(i, N, h) {
                sh += A[i];
                sh -= A[i - h];
                if (sh == h)
                    ans += SB[w];
            }
        }
    }

    cout << ans << endl;
    return 0;
}