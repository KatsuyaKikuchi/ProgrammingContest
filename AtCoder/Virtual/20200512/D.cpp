#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    vector<pll> ans;
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] % 2 == 0)
                continue;
            if (j + 1 < W) {
                A[i][j]--;
                A[i][j + 1]++;
                ans.push_back(pll(i + 1, j + 1));
                ans.push_back(pll(i + 1, j + 2));
            }
            else if (i + 1 < H) {
                A[i][j]--;
                A[i + 1][j]++;
                ans.push_back(pll(i + 1, j + 1));
                ans.push_back(pll(i + 2, j + 1));
            }
        }
    }
    ll N = ans.size();
    cout << N / 2 << endl;
    REP(i, N / 2) {
        ll p = i * 2, q = i * 2 + 1;
        cout << ans[p].first << " " << ans[p].second << " " << ans[q].first << " " << ans[q].second << endl;
    }
    return 0;
}