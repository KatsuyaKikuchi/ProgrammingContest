#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll s = INF;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        s = std::min(s, A[i].first + A[i].second);
    }

    ll t = INF;
    REP(i, N) {
        FOR(j, N, i + 1) {
            t = std::min({t, std::max(A[i].first, A[j].second), std::max(A[i].second, A[j].first)});
        }
    }

    cout << std::min(s, t) << endl;
    return 0;
}