#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll S[100005];
ll M[100005];
bool dp[100005][5][5][5];

ll T[3];
char K[3] = {'A', 'B', 'C'};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N >> T[0] >> T[1] >> T[2];
    REP(i, N) {
        string s;
        cin >> s;
        if (s == "AB")
            S[i] = pll(0, 1);
        if (s == "BC")
            S[i] = pll(1, 2);
        if (s == "AC")
            S[i] = pll(0, 2);
    }

    vector<ll> v(N);
    memset(dp, 0, sizeof(dp));
    REP(a, std::min(T[0] + 1, 5LL)) {
        REP(b, std::min(T[1] + 1, 5LL)) {
            REP(c, std::min(T[2] + 1, 5LL)) {
                dp[0][a][b][c] = true;
            }
        }
    }

    REP(i, N) {
        ll n = S[i].first, m = S[i].second;
        REP(a, 5) {
            REP(b, 5) {
                REP(c, 5) {
                    bool t = false;
                    if (n == 0 && m == 1) {
                        if (a - 1 >= 0 && b + 1 < 5)
                            t |= dp[i][a - 1][b + 1][c];
                        if (a + 1 < 5 && b - 1 >= 0)
                            t |= dp[i][a + 1][b - 1][c];
                    }
                    else if (n == 0 && m == 2) {
                        if (a - 1 >= 0 && c + 1 < 5)
                            t |= dp[i][a - 1][b][c + 1];
                        if (a + 1 < 5 && c - 1 >= 0)
                            t |= dp[i][a + 1][b][c - 1];
                    }
                    else if (n == 1 && m == 2) {
                        if (b - 1 >= 0 && c + 1 < 5)
                            t |= dp[i][a][b - 1][c + 1];
                        if (b + 1 < 5 && c - 1 >= 0)
                            t |= dp[i][a][b + 1][c - 1];
                    }

                    dp[i + 1][a][b][c] |= t;
                }
            }
        }
    }

    bool exist = false;
    REP(a, 5) {
        REP(b, 5) {
            REP(c, 5) {
                exist |= dp[N][a][b][c];
            }
        }
    }

    if (exist) {
        cout << "Yes" << endl;
        vector<ll> v(N);
        for (ll i = N - 1; i >= 0; --i) {
            ll n = S[i].first, m = S[i].second;
            bool sec = false;
            REP(a, 5) {
                if (sec)
                    break;
                REP(b, 5) {
                    if (sec)
                        break;
                    REP(c, 5) {
                        if (!dp[i + 1][a][b][c])
                            continue;


                        if (n == 0 && m == 1) {
                            if (a - 1 >= 0 && b + 1 < 5)
                                if (dp[i][a - 1][b + 1][c]) {
                                    v[i] = 1;
                                    sec = true;
                                    break;
                                }
                            if (a + 1 < 5 && b - 1 >= 0)
                                if (dp[i][a + 1][b - 1][c]) {
                                    v[i] = 0;
                                    sec = true;
                                    break;
                                }
                        }
                        else if (n == 0 && m == 2) {
                            if (a - 1 >= 0 && c + 1 < 5)
                                if (dp[i][a - 1][b][c + 1]) {
                                    v[i] = 2;
                                    sec = true;
                                    break;
                                }
                            if (a + 1 < 5 && c - 1 >= 0)
                                if (dp[i][a + 1][b][c - 1]) {
                                    v[i] = 0;
                                    sec = true;
                                    break;
                                }
                        }
                        else if (n == 1 && m == 2) {
                            if (b - 1 >= 0 && c + 1 < 5)
                                if (dp[i][a][b - 1][c + 1]) {
                                    v[i] = 2;
                                    sec = true;
                                    break;
                                }
                            if (b + 1 < 5 && c - 1 >= 0)
                                if (dp[i][a][b + 1][c - 1]) {
                                    v[i] = 1;
                                    sec = true;
                                    break;
                                }
                        }
                    }
                }
            }
        }

        REP(i, N) {
            cout << K[v[i]] << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
