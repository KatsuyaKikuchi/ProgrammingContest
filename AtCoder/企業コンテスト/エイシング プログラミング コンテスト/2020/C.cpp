#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll n) {
    ll x = 1;
    ll ret = 0;
    while (true) {
        if (x * x > n)
            break;
        ll y = 1;
        while (true) {
            if (x * x + y * y + x * y > n)
                break;
            ll z = 1;
            while (true) {
                ll s = x * x + y * y + z * z + x * y + y * z + z * x;

                if (s > n)
                    break;
                if (s == n)
                    ret++;
                z++;
            }
            y++;
        }
        x++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    REP(i, N) {
        cout << solve(i + 1) << endl;
    }
    return 0;
}