#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
pll A[100005];
std::map<pll, bool> mp;

bool test(ll x, ll y) {
    vector<vector<bool>> dp(100, vector<bool>(100, true));
    REP(i, N) {
        dp[A[i].first][A[i].second] = false;
    }
    dp[0][0] = false;
    REP(i, x + 1) {
        REP(j, y + 1) {
            if (!dp[i][j])
                continue;
            bool e = false;
            REP(k, i) {
                if (!dp[k][j])
                    e = true;
            }
            REP(k, j) {
                if (!dp[i][k])
                    e = true;
            }
            dp[i][j] = e;
        }
    }

    return dp[x][y];
}

vector<pll> v;

bool solve() {
    ll X, Y;
    cin >> X >> Y;
    if (mp[pll(X, Y)])
        return false;


#if true
    return test(X, Y);
#endif
}

struct Data {
    pll g;
    ll index;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        mp[A[i]] = true;
    }

    v.push_back(pll(0, 0));
    vector<bool> used(N, false);
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>>
            qx([](Data a, Data b) { return a.g.first > b.g.first; }),
            qy([](Data a, Data b) { return a.g.second > b.g.second; });
    REP(i, N) {
        qx.push(Data{A[i], i});
        qy.push(Data{A[i], i});
    }

    pll g(0, 0);
    while (!qx.empty() || !qy.empty()) {
        while (!qx.empty()) {
            auto t = qx.top();
            if (used[t.index] || (t.g.first <= g.first && t.g.second <= g.second)) {
                qx.pop();
            }
            else {
                break;
            }
        }
        while (!qy.empty()) {
            auto t = qy.top();

            if (used[t.index] || (t.g.first <= g.first && t.g.second <= g.second)) {
                qy.pop();
            }
            else {
                break;
            }
        }

        pll x(-1, -1), y(-1, -1);
        if (qx.empty()) {
            x = qx.top().g;
        }
        if (qy.empty()) {
            y = qy.top().g;
        }

        if (x.first < 0) {
            if (y.first < 0)
                break;
            //! use y
            used[qy.top().index] = true;
        }
        else if (y.first < 0) {
            //! use x
            used[qx.top().index] = true;
        }
        else {

        }
    }

    REP(i, M) {
        if (solve())
            cout << "WIN" << endl;
        else
            cout << "LOSE" << endl;
    }
    return 0;
}