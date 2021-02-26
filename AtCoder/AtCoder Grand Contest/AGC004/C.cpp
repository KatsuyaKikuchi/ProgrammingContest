#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }

    vector<string> R(H, ""), B(H, "");
    REP(i, H) {
        REP(j, W) {
            R[i].push_back('.');
            B[i].push_back('.');
        }
        R[i][0] = '#';
        B[i][W - 1] = '#';
        REP(j, W - 1) {
            if (i % 2 == 0)
                R[i][j] = '#';
            else
                B[i][W - 1 - j] = '#';
        }
    }

    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#') {
                R[i][j] = B[i][j] = '#';
            }
        }
    }

    REP(i, H) {
        cout << R[i] << endl;
    }
    cout << endl;
    REP(i, H) {
        cout << B[i] << endl;
    }

    return 0;
}