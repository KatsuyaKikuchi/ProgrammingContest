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
    ll N, D, K;
    cin >> N >> D >> K;
    vector<pll> R(D);
    REP(i, D) {
        cin >> R[i].first >> R[i].second;
    }
    vector<pll> S(K);
    REP(i, K) {
        cin >> S[i].first >> S[i].second;
    }
    vector<ll> ans(K, INF);
    REP(d, D) {
        REP(i, K) {
            if (S[i].first < R[d].first || R[d].second < S[i].first)
                continue;
            if (S[i].first < S[i].second)
                S[i].first = std::min(S[i].second, R[d].second);
            else
                S[i].first = std::max(S[i].second, R[d].first);
            if (S[i].first == S[i].second)
                ans[i] = std::min(ans[i], d + 1);
        }
    }
    REP(i, K) {
        cout << ans[i] << endl;
    }
    return 0;
}