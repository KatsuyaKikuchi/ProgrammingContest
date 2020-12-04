#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[1005];
string T[2];

ll H, W;
ll x[4] = {0, 1, 0, 1};
ll y[4] = {0, 0, 1, 1};
char C[3] = {'J', 'O', 'I'};

ll dx[4] = {-1, -1, 0, 0};
ll dy[4] = {-1, 0, -1, 0};

ll solve(ll h, ll w) {
    ll s = 0;
    char c = S[h][w];
    REP(n, 3) {
        S[h][w] = C[n];
        ll m = 0;
        REP(i, 4) {
            bool exist = true;
            REP(j, 4) {
                ll nx = dx[i] + x[j] + h, ny = dy[i] + y[j] + w;
                if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
                    exist = false;
                    break;
                }

                if (S[nx][ny] != T[x[j]][y[j]])
                    exist = false;
            }
            if (exist)
                m++;
        }
        s = std::max(s, m);
    }
    S[h][w] = c;
    REP(i, 4) {
        bool exist = true;
        REP(j, 4) {
            ll nx = dx[i] + x[j] + h, ny = dy[i] + y[j] + w;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
                exist = false;
                break;
            }

            if (S[nx][ny] != T[x[j]][y[j]])
                exist = false;
        }
        if (exist)
            s--;
    }
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    REP(i, 2) {
        cin >> T[i];
    }

    ll sum = 0;
    REP(i, H) {
        REP(j, W) {
            bool exist = true;
            REP(n, 4) {
                ll nx = i + x[n], ny = j + y[n];
                if (nx >= H || ny >= W) {
                    exist = false;
                    break;
                }
                if (S[nx][ny] != T[x[n]][y[n]])
                    exist = false;
            }
            if (exist)
                sum++;
        }
    }

    ll ans = sum;
    REP(i, H) {
        REP(j, W) {
            ll s = solve(i, j);
            ans = std::max(ans, sum + s);
        }
    }
    cout << ans << endl;
    return 0;
}