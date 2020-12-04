#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll q;
        cin >> q;
        REP(j, N) {
            if (q == S[j]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}