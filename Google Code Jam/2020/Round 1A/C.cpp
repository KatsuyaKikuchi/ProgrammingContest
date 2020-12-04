#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[105][105];
ll T[105][105];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

ll solve(ll R, ll C) {
    ll ret = 0;
    if (R * C > 1000) {
        return ret;
    }
    while (true) {
        REP(i, R) {
            REP(j, C) {
                ret += S[i][j];
            }
        }
        bool update = false;

        REP(i, R) {
            REP(j, C) {
                ll sum = 0;
                ll s = 0;
                T[i][j] = S[i][j];
                if (T[i][j] == 0)
                    continue;

                REP(n, 4) {
                    ll p = 1;
                    while (true) {
                        ll nx = i + x[n] * p;
                        ll ny = j + y[n] * p;
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                            break;
                        p++;
                        if (S[nx][ny] == 0)
                            continue;
                        s++;
                        sum += S[nx][ny];
                        break;
                    }
                }

                if (s > 0 && sum > T[i][j] * s)
                    T[i][j] = 0;
            }
        }

        REP(i, R) {
            REP(j, C) {
                if (T[i][j] != S[i][j])
                    update = true;
                S[i][j] = T[i][j];
            }
        }
        if (!update)
            break;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll R, C;
        cin >> R >> C;
        REP(i, R) {
            REP(j, C) {
                cin >> S[i][j];
            }
        }
        cout << "Case #" << q + 1 << ": " << solve(R, C) << endl;
    }
    return 0;
}