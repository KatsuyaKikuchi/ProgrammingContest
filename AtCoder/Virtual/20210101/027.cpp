#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    pll g;
    cin >> g.first >> g.second;
    string X;
    cin >> X;
    ll H = 9, W = 9;
    REP(i, H) {
        cin >> S[i];
    }
    g.first--;
    g.second--;
    pll dt(0, 0);
    REP(i, X.length()) {
        switch (X[i]) {
            case 'U':
                dt.first--;
                break;
            case 'D':
                dt.first++;
                break;
            case 'L':
                dt.second--;
                break;
            case 'R':
                dt.second++;
                break;
        }
    }

    string ans = "";
    while (ans.size() < 4) {
        ans.push_back(S[g.second][g.first]);
        ll y = g.second + dt.first;
        if (y < 0 || y >= H)
            dt.first *= -1;
        ll x = g.first + dt.second;
        if (x < 0 || x >= W)
            dt.second *= -1;
        g.first += dt.second;
        g.second += dt.first;
    }
    cout << ans << endl;
    return 0;
}