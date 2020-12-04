
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 1000;
    ll x = 0;
    REP(i, N) {
        if (i < N - 1) {
            if (A[i] < A[i + 1] && x == 0) {
                x = ans / A[i];
                ans %= A[i];
                continue;
            }
        }

        if (i > 0) {
            if (i == N - 1 || (A[i] > A[i + 1] && x > 0)) {
                ans += A[i] * x;
                x = 0;
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}