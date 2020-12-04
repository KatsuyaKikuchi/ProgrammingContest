#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        ll N;
        cin >> N;
        if (N == 0)
            break;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        ll s = 0;
        ll sum = 0;
        ll ans = -INF;
        REP(i, N) {
            sum += A[i];
            while (sum <= 0 && s < i)
                sum -= A[s++];
            while (A[s] < 0 && s < i)
                sum -= A[s++];
            ans = std::max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}