#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    if (K == 1) {
        ans = N;
    }
    else {
        ll s = 0;
        REP(i, N - 1) {
            if (A[i + 1] > A[i]) {
                if (i - s + 2 >= K) {
                    ans++;
                    s++;
                }
                continue;
            }
            s = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}