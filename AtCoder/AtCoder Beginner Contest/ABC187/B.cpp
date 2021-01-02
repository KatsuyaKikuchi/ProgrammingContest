#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[10005];

bool check(pll a, pll b) {
    ll x = abs(a.first - b.first);
    ll y = abs(a.second - b.second);
    return y <= x;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i + 1) {
            if (check(A[i], A[j]))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}