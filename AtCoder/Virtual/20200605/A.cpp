#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }

    ll ans = 0;
    REP(b, pow(2LL, N)) {
        pll p(0, 0);
        REP(i, N) {
            if ((b >> i) & 1) {
                p.first += A[i].first;
                p.second += A[i].second;
            }
        }
        ans = std::max(ans, p.first - p.second);
    }
    cout << ans << endl;

    return 0;
}