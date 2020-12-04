#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[10005][55];

ll calc(ll cnt, pll cake, vector<ll> &A) {
    vector<pll> v;
    ll N = A.size();
    REP(i, N) {
        ll p = (A[i] * cake.second) / cake.first;
        ll c = p;
        if ((A[i] * cake.second) % cake.first == 0) {
            c = std::max(0LL, c - 1);
        }
        if (p == 0)
            c = INF;
        v.push_back(pll(p, c));
    }
    REP(i, N + 1) {
        REP(j, cnt + 1) {
            dp[i][j] = cnt - 1;
        }
    }
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, cnt + 1) {
            dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
            ll nxt = j + v[i].first;
            ll sum = v[i].second;
            if (nxt > cnt) {
                nxt = cnt;
                sum = cnt - j;
            }
            dp[i + 1][nxt] = std::min(dp[i + 1][nxt], dp[i][j] + sum);
        }
    }
#if false
    cout << "---------------" << endl;
    REP(i, N + 1) {
        REP(j, cnt + 1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return dp[N][cnt];
}

void solve() {
    ll N, D;
    cin >> N >> D;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll ret = D - 1;
    REP(i, N) {
        REP(j, D) {
            pll p(A[i], j + 1);
            ret = std::min(calc(D, p, A), ret);
        }
    }
    cout << ret << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}