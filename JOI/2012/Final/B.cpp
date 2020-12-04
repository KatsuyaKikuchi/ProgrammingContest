#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[5005];
ll B[5005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    ll ans = 0;
    REP(i, M) {
        ll s = 0;
        ll bi = i;
        REP(j, N) {
            if (B[bi] == A[j]) {
                s++;
                bi++;
            }
            if (bi >= M)
                break;
        }
        ans = std::max(ans, s);
    }
    cout << ans << endl;
    return 0;
}