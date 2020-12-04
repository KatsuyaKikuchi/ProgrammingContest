#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
pll A[505];


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    ll rs = 0, bs = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        rs += A[i].first;
        bs += A[i].second;
    }

    ll ans = rs / K + bs / K;
    rs %= K;
    bs %= K;

    REP(i, N) {
        bool e = false;
        REP(j, std::min(A[i].first, rs) + 1) {
            if (A[i].second >= K - j && K - j <= bs) {
                e = true;
                break;
            }
        }
        if (e) {
            ans++;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}