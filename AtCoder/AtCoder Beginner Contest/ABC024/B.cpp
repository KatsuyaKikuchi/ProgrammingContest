#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    A.push_back(INF);
    ll p = A[0];
    ll ans = 0;
    REP(i, A.size()) {
        ans += std::min(A[i], p + T) - p;
        p = A[i];
    }
    cout << ans << endl;
    return 0;
}