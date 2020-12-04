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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    ll sum = 0;
    std::map<ll, ll> M;

    M[0] = 1;
    ll left = 0;
    REP(i, N) {
        sum += A[i];
        left = std::max(left, M[sum]);

        ans += i + 1 - left;

        M[sum] = i + 2;
    }
    cout << ans << endl;

    return 0;
}