#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i + 1) {
            if (A[i] == A[j])
                continue;
            FOR(k, N, j + 1) {
                if ((A[i] == A[k]) || (A[j] == A[k]))
                    continue;
                ll sum = A[i] + A[j] + A[k];
                ll mx = std::max({A[i], A[j], A[k]});
                if (sum - mx > mx)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}