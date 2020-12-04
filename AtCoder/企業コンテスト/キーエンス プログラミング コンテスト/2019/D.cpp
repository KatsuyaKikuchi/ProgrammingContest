#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005];
ll B[1005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    ll ans = 1;
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    sort(B, B + M, [](ll a, ll b) { return a > b; });
    REP(i, N - 1) {
        if (A[i] == A[i + 1]) {
            ans = 0;
        }
    }
    REP(i, M - 1) {
        if (B[i] == B[i + 1]) {
            ans = 0;
        }
    }

    ll a = 0, b = 0;
    for (ll n = N * M; n > 0; --n) {
        if (a < N - 1 && A[a + 1] == n)
            a++;
        if (b < M - 1 && B[b + 1] == n)
            b++;

        if (A[a] < n || B[b] < n) {
            ans = 0;
            break;
        }

        ll x = A[a] == n ? 1LL : a + 1;
        ll y = B[b] == n ? 1LL : b + 1;
        if (A[a] == n || B[b] == n) {
            ans = (ans * x * y) % MOD;
        }
        else {
            ll s = x * y - (N * M - n);
            if (s <= 0) {
                ans = 0;
                break;
            }
            ans = (ans * s) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}