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
    ll ans = INF;
    {
        ll t = 0;
        ll s = 0;
        REP(i, N) {
            s += A[i];
            if (i % 2 == 0) {
                if (s <= 0) {
                    t += 1 - s;
                    s = 1;
                }
            }
            else {
                if (s >= 0) {
                    t += s + 1;
                    s = -1;
                }
            }
        }
        ans = std::min(ans, t);
    }
    {
        ll t = 0;
        ll s = 0;
        REP(i, N) {
            s += A[i];
            if (i % 2 == 1) {
                if (s <= 0) {
                    t += 1 - s;
                    s = 1;
                }
            }
            else {
                if (s >= 0) {
                    t += s + 1;
                    s = -1;
                }
            }
        }
        ans = std::min(ans, t);
    }
    cout << ans << endl;
    return 0;
}