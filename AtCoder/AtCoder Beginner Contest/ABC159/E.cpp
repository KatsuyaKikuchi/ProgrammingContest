#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H, W, K;
string S[15];

ll solve(ll div) {
    vector<vector<string>> v;
    vector<string> t;
    REP(i, H) {
        t.push_back(S[i]);
        if (i == H - 1 || ((div >> i) & 1) == 1) {
            v.push_back(t);
            t.clear();
        }
    }

    ll ret = v.size() - 1;
    vector<ll> s(v.size(), 0);
    REP(w, W) {
        vector<ll> ss(v.size(), 0);
        REP(i, v.size()) {
            REP(j, v[i].size()) {
                ss[i] += v[i][j][w] - '0';
            }
            if (ss[i] > K)
                return INF;
        }

        bool over = false;
        REP(i, v.size()) {
            if (s[i] + ss[i] > K)
                over = true;
        }

        if (over) {
            REP(i, v.size()) {
                s[i] = 0;
            }
            ret++;
        }

        REP(i, v.size()) {
            s[i] += ss[i];
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = INF;
    REP(i, pow(2, H - 1)) {
        ans = std::min(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}