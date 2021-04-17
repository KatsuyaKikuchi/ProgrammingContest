#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<pll> V(N);
    ll sum = 0;
    REP(i, N) {
        cin >> V[i].first >> V[i].second;
        sum += V[i].first * V[i].second;
    }

    ll ret = 0;
    for (ll s = sum - 2; s >= std::max(1LL, sum - 10000); s--) {
        bool enable = true;
        ll t = s;
        ll p = 0;
        REP(i, N) {
            ll cnt = 0;
            while (t % V[i].first == 0) {
                cnt++;
                t /= V[i].first;
                p += V[i].first;
            }
            if (cnt > V[i].second) {
                enable = false;
                break;
            }
        }
        if (t > 1)
            enable = false;

        if (enable && p == sum - s) {
            ret = s;
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}