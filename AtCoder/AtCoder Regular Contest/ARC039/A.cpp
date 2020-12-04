#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    ll ans = -INF;
    REP(i, 3) {
        REP(j, 10) {
            if (i == 0 && j == 0)
                continue;
            {
                ll a = 0;
                ll b = 0;
                REP(k, 3) {
                    a = a * 10 + A[k] - '0';
                    if (i != k)
                        b = b * 10 + B[k] - '0';
                    else
                        b = b * 10 + j;
                }
                ans = std::max(a - b, ans);
            }
            {
                ll a = 0;
                ll b = 0;
                REP(k, 3) {
                    if (i != k)
                        a = a * 10 + A[k] - '0';
                    else
                        a = a * 10 + j;
                    b = b * 10 + B[k] - '0';
                }
                ans = std::max(a - b, ans);
            }
        }
    }

    cout << ans << endl;
    return 0;
}