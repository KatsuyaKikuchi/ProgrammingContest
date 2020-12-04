#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    ll a = 0;
    while (a * 3LL <= N) {
        ll b = 0;
        while (a * 3LL + b * 5LL <= N) {
            ll c = N - (3 * a + 5 * b);
            if (c % 7 == 0) {
                cout << a << " " << b << " " << (c / 7) << endl;
                return;
            }
            b++;
        }
        a++;
    }
    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}