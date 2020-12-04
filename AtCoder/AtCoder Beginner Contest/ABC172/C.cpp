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

    ll ai = 0, bi = 0;
    ll s = 0;
    while (ai < N && s <= K) {
        if (s + A[ai] > K)
            break;
        s += A[ai++];
    }
    ll ans = ai;
    ai--;
    REP(i, M) {
        while (s + B[i] > K && ai >= 0) {
            s -= A[ai--];
        }
        s += B[i];
        if (s <= K) {
            ans = std::max(ans, i + 1 + ai + 1);
        }
    }
    cout << ans << endl;
    return 0;
}