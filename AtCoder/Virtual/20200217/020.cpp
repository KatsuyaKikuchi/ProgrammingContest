#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[205];
ll dp[205][200005];

int main() {
    ll N, W;
    cin >> N >> W;
    ll mw = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        mw = std::max(mw, A[i].second);
    }

    if (N <= 30) {
        //! 半分全列挙
        ll n = N / 2;
        ll m = N - n;
        vector<pll> v;
        REP(i, pow(2LL, n)) {
            ll w = 0, c = 0;
            REP(j, n) {
                if ((i >> j) & 1) {
                    w += A[j].second;
                    c += A[j].first;
                }
            }
            v.push_back(pll(w, c));
        }

        sort(v.begin(), v.end(),
             [](pll a, pll b) { return a.first < b.first; });
        REP(i, v.size() - 1) {
            v[i + 1].second = std::max(v[i + 1].second, v[i].second);
        }
        ll ans = 0;
        REP(i, pow(2LL, m)) {
            ll w = 0, c = 0;
            REP(j, m) {
                if ((i >> j) & 1) {
                    w += A[n + j].second;
                    c += A[n + j].first;
                }
            }
            if (w > W)
                continue;

            ll ok = -1, ng = v.size();
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (v[mid].first + w <= W)
                    ok = mid;
                else
                    ng = mid;
            }
            if (ok >= 0)
                c += v[ok].second;
            ans = std::max(ans, c);
        }
        cout << ans << endl;
    }
    else if (mw <= 1000) {
        //! dp
        memset(dp, 0, sizeof(dp));
        REP(i, N) {
            REP(j, std::min(1000 * N, W) + 1) {
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
                if (j - A[i].second >= 0)
                    dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j - A[i].second] + A[i].first);
            }
        }
        ll ans = 0;
        REP(i, std::min(1000 * N, W) + 1) {
            ans = std::max(ans, dp[N][i]);
        }
        cout << ans << endl;
    }
    else {
        //! dp
        REP(i, N + 1) {
            REP(j, 1000 * N + 1) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        REP(i, N) {
            REP(j, 1000 * N + 1) {
                dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
                if (j - A[i].first >= 0) {
                    dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j - A[i].first] + A[i].second);
                }
            }
        }

        for (ll i = 1000 * N; i >= 0; --i) {
            if (dp[N][i] <= W) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}