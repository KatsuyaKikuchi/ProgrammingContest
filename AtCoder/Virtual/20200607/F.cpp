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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    ll x = 1;
    REP(i, N) {
        if (A[i] == x) {
            x++;
            continue;
        }
        ll p = A[i] / x;
        ans += p;
        A[i] -= p * x;
        if (A[i] == 0) {
            A[i]++;
            ans--;
        }
        x = std::max(A[i] + 1, x);
    }
    cout << ans << endl;
    return 0;
}