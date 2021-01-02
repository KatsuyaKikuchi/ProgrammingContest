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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    vector<vector<bool>> v(H + 1, vector<bool>(W + 1, true));
    for (ll i = H - 1; i >= 0; --i) {
        for (ll j = W - 1; j >= 0; --j) {
            if (S[i][j] == '#')
                continue;
            bool e = false;
            if (!v[i + 1][j] || !v[i][j + 1] || !v[i + 1][j + 1])
                e = true;
            v[i][j] = e;
        }
    }

    if (v[0][0])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}