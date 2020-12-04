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
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        ll n = N / 2;
        if (n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        ll s = 0;
        REP(i, n) {
            cout << 2 * (i + 1) << " ";
            s += 2 * (i + 1);
        }
        REP(i, n - 1) {
            cout << 2 * i + 1 << " ";
            s -= 2 * i + 1;
        }
        cout << s << endl;
    }
    return 0;
}