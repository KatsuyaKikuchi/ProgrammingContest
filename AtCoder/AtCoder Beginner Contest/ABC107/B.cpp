#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

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
    vector<string> v;
    REP(i, H) {
        bool b = false;
        REP(j, W) {
            if (S[i][j] == '#')
                b = true;
        }
        if (b)
            v.push_back(S[i]);
    }
    vector<ll> t;
    REP(i, W) {
        bool b = false;
        REP(j, v.size()) {
            if (v[j][i] == '#')
                b = true;
        }
        if (b)
            t.push_back(i);
    }

    REP(i, v.size()) {
        REP(j, t.size()) {
            cout << v[i][t[j]];
        }
        cout << endl;
    }
    return 0;
}