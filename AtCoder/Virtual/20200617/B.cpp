#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 20002;

bool dp[8005][MAX];
vector<ll> X, Y;

bool check(ll x, ll y) {
    {
        memset(dp, 0, sizeof(dp));
        dp[0][MAX / 2] = true;

        REP(i, X.size()) {
            REP(j, MAX + 1) {
                if (!dp[i][j])
                    continue;
                if (j - X[i] >= 0 && i > 0)
                    dp[i + 1][j - X[i]] = true;
                if (j + X[i] < MAX)
                    dp[i + 1][j + X[i]] = true;
            }
        }
        if (!dp[X.size()][(MAX / 2) + x])
            return false;
    }
    {
        memset(dp, 0, sizeof(dp));
        dp[0][(MAX / 2)] = true;

        REP(i, Y.size()) {
            REP(j, MAX + 1) {
                if (!dp[i][j])
                    continue;
                if (j - Y[i] >= 0)
                    dp[i + 1][j - Y[i]] = true;
                if (j + Y[i] < MAX)
                    dp[i + 1][j + Y[i]] = true;
            }
        }
        if (!dp[Y.size()][(MAX / 2) + y])
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
#if true
    string S;
    cin >> S;
    ll x, y;

    cin >> x >> y;

    X.clear();
    Y.clear();
    ll cnt = 0;
    bool rot = false;
    REP(i, S.length()) {
        if (S[i] == 'F') {
            cnt++;
            continue;
        }
        if (rot)
            Y.push_back(cnt);
        else
            X.push_back(cnt);
        cnt = 0;
        rot = !rot;
    }
    if (rot)
        Y.push_back(cnt);
    else
        X.push_back(cnt);
#endif

#if false
    REP(i, X.size()) {
        cout << X[i] << " ";
    }
    cout << endl;
    REP(i, Y.size()) {
        cout << Y[i] << " ";
    }
    cout << endl;
#endif
    if (check(x, y))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}