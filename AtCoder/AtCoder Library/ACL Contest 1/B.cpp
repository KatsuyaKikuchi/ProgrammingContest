#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    ll num = 1;
    ll ans = INF;
    while (num * num <= 2LL * N) {
        if (2LL * N % num == 0) {
            ll p = 2LL * N / num;
            {
                vector<ll> v{0, -1};
                vector<ll> r{num, p};
                pll c = atcoder::crt(v, r);
                if (c.second > 0)
                    ans = std::min(ans, c.first);
            }
            {
                vector<ll> v{0, -1};
                vector<ll> r{p, num};
                pll c = atcoder::crt(v, r);
                if (c.second > 0 && c.first > 0)
                    ans = std::min(ans, c.first);
            }
        }
        num++;
    }
    cout << ans << endl;
    return 0;
}