#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll P[2005];

ll calc(ll l, ll r, pll p) {
    ll a = std::max(p.first, l);
    ll b = std::min(p.second, r);
    return std::max(0LL, b - a + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    REP(i, M) {
        cin >> P[i].first >> P[i].second;
        P[i].first--;
        P[i].second--;
    }

    sort(P, P + M, [](pll a, pll b) { return a.second < b.second; });
    ll ans = 0;


#if false
    ll ans = 0;
    REP(i, N) {
        if (i + K > N)
            break;
        REP(j, N) {
            if (j + K > N)
                break;
            ll sum = 0;
            REP(m, M) {
                ll a = calc(i, i + K - 1, P[m]);
                ll b = calc(j, j + K - 1, P[m]);
                sum += std::max(a, b);
            }
            ans = std::max(sum, ans);
        }
    }

    cout << ans << endl;
#endif

    return 0;
}