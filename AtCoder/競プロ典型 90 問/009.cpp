#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> V(N);
    REP(i, N) {
        cin >> V[i].first >> V[i].second;
    }
    double ans = 0;
    REP(i, N) {
        vector<double> v;
        REP(j, N) {
            if (i == j)
                continue;
            pll p(V[j].first - V[i].first, V[j].second - V[i].second);
            double theta = (atan2(p.second, p.first) / M_PI) * 180.0 + 180.0;
            v.push_back(theta);
            v.push_back(theta + 360);
        }
        sort(v.begin(), v.end());
        ll index = 0;
        REP(j, v.size() / 2) {
            double r = v[j] + 180.0;
            while (v[index] < r) {
                index++;
            }
            double diff = std::max(
                    std::min(abs(360 - (v[index] - v[j])), v[index] - v[j]),
                    std::min(abs(360 - (v[index - 1] - v[j])), v[index - 1] - v[j]));
            ans = std::max(ans, diff);
        }
    }

    cout << OF64 << ans << endl;
    return 0;
}