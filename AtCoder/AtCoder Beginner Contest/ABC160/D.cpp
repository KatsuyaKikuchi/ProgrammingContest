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
    ll N, X, Y;
    cin >> N >> X >> Y;
    for (ll k = 1; k < N; ++k) {
        ll s = 0;
        for (ll i = 1; i <= N; ++i) {

            if (abs(X - i) >= k) {
                if (i + k <= N)
                    s++;
                continue;
            }

            if (i + k <= N) {
                //! i+kまでの距離
                ll l = abs(X - i) + 1 + abs(i + k - Y);
                if (l >= k)
                    s++;
            }

            ll a = Y - (k - abs(X - i) - 1);
            ll b = Y + (k - abs(X - i) - 1);
            if (a == b) {
                if (a > i && a - i > k)
                    s++;
            }
            else {
                if (a > 0 && a > i && a - i > k)
                    s++;
                if (b <= N && b > i && b - i > k)
                    s++;
            }

        }
        cout << s << endl;
    }
    return 0;
}