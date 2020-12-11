#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll g;
    ll cost;
};

ll dt[3] = {-2, -1, 0};

void solve() {
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    REP(x, N) {
        ll n = 0;
        REP(y, N) {
            if (S[x][y] == 'X')
                n++;
            else
                n = 0;
            if (n == 3) {
                ll sum[3] = {0, 0, 0};
                REP(j, 3) {
                    ll ty = y + dt[j];
                    REP(i, 3) {
                        ll p0 = dt[i] + x;
                        ll p1 = p0 + 1;
                        ll p2 = p1 + 1;
                        if (p0 < 0 || p2 >= N)
                            continue;
                        if (S[p0][ty] == 'X' && S[p1][ty] == 'X' && S[p2][ty] == 'X') {
                            sum[j]++;
                        }
                    }
                }

                if (sum[2] >= sum[1] && sum[2] >= sum[0]) {
                    S[x][y] = 'O';
                    n = 0;
                }
                else if (sum[1] >= sum[0]) {
                    S[x][y - 1] = 'O';
                    n = 1;
                }
                else {
                    S[x][y - 2] = 'O';
                    n = 2;
                }
            }
        }
    }
    REP(j, N) {
        ll n = 0;
        REP(i, N) {
            if (S[i][j] == 'X')
                n++;
            else
                n = 0;

            if (n == 3) {
                S[i][j] = 'O';
                n--;
            }
        }
    }

#if false
    REP(x, N) {
        REP(y, N) {
            ll sum = 0;
            REP(i, 3) {
                ll p0 = dt[i] + x;
                ll p1 = p0 + 1;
                ll p2 = p1 + 1;
                if (p0 < 0 || p2 >= N)
                    continue;
                if (S[p0][y] == 'X' && S[p1][y] == 'X' && S[p2][y] == 'X') {
                    sum++;
                }
            }

            if (sum > 1) {
                S[x][y] = 'O';
            }
        }
    }
#endif

#if false
    REP(i, N) {
        ll n = 0;
        REP(j, N) {
            if (S[i][j] == 'X')
                n++;
            else
                n = 0;

            if (n == 3) {
                S[i][j] = 'O';
                n--;
            }
        }
    }
    REP(j, N) {
        ll n = 0;
        REP(i, N) {
            if (S[i][j] == 'X')
                n++;
            else
                n = 0;

            if (n == 3) {
                S[i][j] = 'O';
                n--;
            }
        }
    }
#endif

    REP(i, N) {
        cout << S[i] << endl;
    }
#if false
    vector<vector<ll>> A(N, vector<ll>(N, 0));
    REP(i, N) {
        ll n = 0;
        REP(j, N) {
            if (S[i][j] == 'X')
                n++;
            else
                n = 0;
            if (n == 3) {
                A[i][j]++;
                A[i][j - 1]++;
                A[i][j - 2]++;
                n--;
            }
        }
    }
    REP(j, N) {
        ll n = 0;
        REP(i, N) {
            if (S[i][j] == 'X')
                n++;
            else
                n = 0;
            if (n == 3) {
                A[i][j]++;
                A[i - 1][j]++;
                A[i - 2][j]++;
                n--;
            }
        }
    }

    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost < b.cost; });
    vector<vector<ll>> U(N, vector<ll>(N, 0));
    REP(i, N) {
        REP(j, N) {
            if (A[i][j] == 0)
                continue;
            q.push(Data{pll(i, j), A[i][j]});
        }
    }
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        ll x = t.g.first, y = t.g.second;
        if (U[x][y] > 0) {
            U[x][y]--;
            continue;
        }
        if (A[x][y] == 0)
            continue;

        vector<pll> v;
        REP(i, 3) {
            ll p0 = dt[i] + x;
            ll p1 = p0 + 1;
            ll p2 = p1 + 1;
            if (p0 < 0 || p2 >= N)
                continue;
            if (S[p0][y] == 'X' && S[p1][y] == 'X' && S[p2][y] == 'X') {
                A[p0][y]--;
                A[p1][y]--;
                A[p2][y]--;
                v.push_back(pll(p0, y));
                v.push_back(pll(p1, y));
                v.push_back(pll(p2, y));
            }
        }
        REP(i, 3) {
            ll p0 = dt[i] + y;
            ll p1 = p0 + 1;
            ll p2 = p1 + 1;
            if (p0 < 0 || p2 >= N)
                continue;
            if (S[x][p0] == 'X' && S[x][p1] == 'X' && S[x][p2] == 'X') {
                A[x][p0]--;
                A[x][p1]--;
                A[x][p2]--;
                v.push_back(pll(x, p0));
                v.push_back(pll(x, p1));
                v.push_back(pll(x, p2));
            }
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        S[x][y] = 'O';
        A[x][y] = 0;
        REP(i, v.size()) {
            U[v[i].first][v[i].second]++;
            q.push(Data{v[i], A[v[i].first][v[i].second]});
        }
    }

    REP(i, N) {
        cout << S[i] << endl;
    }
#endif
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