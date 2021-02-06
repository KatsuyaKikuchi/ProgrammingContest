#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

#if true
    REP(i, N) {
        FOR(j, N, i + 1) {
            if (S[i][j] == S[j][i]) {
                cout << "YES" << endl;
                REP(k, M + 1) {
                    ll ret = k % 2 == 0 ? i + 1 : j + 1;
                    cout << ret << " ";
                }
                cout << endl;
                return;
            }
        }
    }
#endif

    if (M % 2 == 1) {
        cout << "YES" << endl;
        REP(k, M + 1) {
            ll ret = k % 2 == 0 ? 1 : 2;
            cout << ret << " ";
        }
        cout << endl;
        return;
    }

    if (N >= 3) {
        cout << "YES" << endl;
        REP(i, 3) {
            ll a = (i + 1) % 3;
            ll b = (i + 2) % 3;
            if (S[a][i] != S[i][b])
                continue;

            ll m = M / 2;
            vector<ll> ans;
            REP(j, m) {
                ll n = j % 2 == 0 ? a : i;
                ans.push_back(n);
            }
            reverse(ans.begin(), ans.end());
            ans.push_back(i);
            REP(j, m) {
                ll n = j % 2 == 0 ? b : i;
                ans.push_back(n);
            }
            REP(j, ans.size()) {
                cout << ans[j] + 1 << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "NO" << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}