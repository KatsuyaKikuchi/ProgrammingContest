#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D, G;
pll P[15];

ll calc(ll bit) {
    ll ret = 0;
    REP(i, D) {
        if ((bit >> i) & 1) {
            ret += 100LL * (i + 1) * P[i].first + P[i].second;
        }
    }
    return ret;
}

int main() {
    cin >> D >> G;
    REP(i, D) {
        cin >> P[i].first >> P[i].second;
    }

    ll ans = INF;
    REP(bit, pow(2LL, D)) {
        ll score = calc(bit);
        ll sum = 0;
        REP(i, D) {
            if ((bit >> i) & 1) {
                sum += P[i].first;
            }
        }
        if (score >= G) {
            ans = std::min(ans, sum);
            continue;
        }
        REP(i, D) {
            if ((bit >> i) & 1)
                continue;
            ll s = (i + 1) * 100LL;
            REP(j, P[i].first) {
                if (score + s * j >= G) {
                    ans = std::min(ans, sum + j);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}