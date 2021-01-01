#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 1;
    bool u = false, d = false;
    FOR(i, N, 1) {
        if (u) {
            if (A[i] < A[i - 1]) {
                u = false;
                ans++;
            }
        }
        else if (d) {
            if (A[i] > A[i - 1]) {
                d = false;
                ans++;
            }
        }
        else {
            if (A[i] > A[i - 1])
                u = true;
            else if (A[i] < A[i - 1])
                d = true;
        }
    }
    cout << ans << endl;
    return 0;
}