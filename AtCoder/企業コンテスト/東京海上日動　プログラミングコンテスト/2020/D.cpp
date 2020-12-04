#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll DIV = 10;
const ll MAX = 100001;

int dp[2LL << DIV][MAX + 5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    memset(dp, 0, sizeof(dp));
    ll bit = pow(2LL, DIV);
    REP(b, std::min(N, bit)) {
        vector<ll> v;
        ll n = b + 1;
        while (n > 0) {
            v.push_back(n - 1);
            n >>= 1;
        }

        REP(i, (1LL << v.size())) {
            int w = 0, t = 0;
            REP(j, v.size()) {
                if (((i >> j) & 1) == 1) {
                    w += A[v[j]].second;
                    t += A[v[j]].first;
                }
            }
            if (w > MAX)
                continue;
            dp[b][w] = std::max(dp[b][w], t);
        }
        REP(i, MAX) {
            dp[b][i + 1] = std::max(dp[b][i], dp[b][i + 1]);
        }
    }

    ll Q;
    cin >>
        Q;
    REP(_, Q) {
        ll V, L;
        cin >> V >>
            L;
        if (V <= bit) {
            cout << dp[V - 1][L] <<
                 endl;
            continue;
        }

        vector<ll> v;
        while (V > bit) {
            v.
                    push_back(V
                              - 1);
            V >>= 1;
        }

        ll ret = 0;
        REP(b, (1LL << v.size())) {
            ll w = 0, t = 0;
            REP(j, v.size()) {
                if (((b >> j) & 1) == 1) {
                    w += A[v[j]].
                            second;
                    t += A[v[j]].
                            first;
                }
                if (w > L)
                    break;
            }
            if (w > L)
                continue;
            ret = std::max(ret, t + dp[V - 1][L - w]);
        }
        cout << ret <<
             endl;
    }
    return 0;
}