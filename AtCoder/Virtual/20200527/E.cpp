#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 16005;

bool dp0[MAX], dp1[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll X, Y;
    cin >> X >> Y;
    vector<ll> x, y;
    ll cnt = 0;
    bool rot = true;
    REP(i, S.length()) {
        if (S[i] == 'T') {
            if (rot)
                x.push_back(cnt);
            else
                y.push_back(cnt);
            cnt = 0;
            rot = !rot;
        }
        else
            cnt++;

        if (i == S.length() - 1) {
            if (rot)
                x.push_back(cnt);
            else
                y.push_back(cnt);
        }
    }

    {
        ll base = 8000;
        memset(dp0, 0, sizeof(dp0));
        dp0[base] = true;
        if (x.size() > 0) {
            dp0[base] = false;
            dp0[base + x[0]] = true;
        }
        FOR(i, x.size(), 1) {
            memset(dp1, 0, sizeof(dp1));
            REP(j, MAX) {
                if (!dp0[j])
                    continue;
                ll p = j - x[i], n = j + x[i];
                if (p >= 0)
                    dp1[p] = true;
                if (n < MAX)
                    dp1[n] = true;
            }
            swap(dp0, dp1);
        }

        if (!dp0[base + X]) {
            cout << "No" << endl;
            return 0;
        }
    }
    {
        ll base = 8000;
        memset(dp0, 0, sizeof(dp0));
        dp0[base] = true;
        REP(i, y.size()) {
            memset(dp1, 0, sizeof(dp1));
            REP(j, MAX) {
                if (!dp0[j])
                    continue;
                ll p = j - y[i], n = j + y[i];
                if (p >= 0)
                    dp1[p] = true;
                if (n < MAX)
                    dp1[n] = true;
            }
            swap(dp0, dp1);
        }

        if (!dp0[base + Y]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}