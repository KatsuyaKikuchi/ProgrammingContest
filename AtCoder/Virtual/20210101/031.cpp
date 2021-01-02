#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
ll dx[3] = {-1, 0, 1};
ll dy[3] = {-1, 0, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    vector<vector<bool>> ans(H, vector<bool>(W, true));
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#')
                continue;
            REP(xi, 3) {
                REP(yi, 3) {
                    ll x = i + dx[xi], y = j + dy[yi];
                    if (x < 0 || x >= H || y < 0 || y >= W)
                        continue;
                    ans[x][y] = false;
                }
            }
        }
    }
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.')
                continue;
            bool e = false;
            REP(xi, 3) {
                REP(yi, 3) {
                    ll x = i + dx[xi], y = j + dy[yi];
                    if (x < 0 || x >= H || y < 0 || y >= W)
                        continue;
                    if (ans[x][y])
                        e = true;
                }
            }
            if (!e) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    cout << "possible" << endl;
    REP(i, H) {
        REP(j, W) {
            if (ans[i][j])
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}