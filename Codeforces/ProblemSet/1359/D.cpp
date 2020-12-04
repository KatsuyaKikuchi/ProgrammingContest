#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    ll offset = 50;
    memset(B, 0, sizeof(B));
    ll sum = 0;
    ll s = 0;
    REP(i, N) {
        sum += A[i];
        B[A[i] + offset]++;
        while (sum <= 0 && s <= i) {
            sum -= A[s];
            B[A[s] + offset]--;
            s++;
        }
        while (s <= i && A[s] < 0) {
            sum -= A[s];
            B[A[s] + offset]--;
            s++;
        }

        ll mx = 0;
        for (ll j = -30; j <= 30; ++j) {
            if (B[j + offset] > 0)
                mx = std::max(mx, j);
        }
        ans = std::max(ans, sum - mx);
    }
    cout << ans << endl;
    return 0;
}