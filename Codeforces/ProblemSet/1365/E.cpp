#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll mx = 0;
    REP(i, N) {
        mx = std::max(mx, A[i]);
        REP(j, N) {
            mx = std::max(mx, A[i] | A[j]);
            REP(k, N) {
                mx = std::max(mx, A[i] | A[j] | A[k]);
            }
        }
    }
    cout << mx << endl;
    return 0;
}