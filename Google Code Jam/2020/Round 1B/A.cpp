#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
char C[4] = {'W', 'S', 'E', 'N'};

string solve(ll X, ll Y) {
    ll sx = 0, sy = 0;
    if (X < 0)
        sx++;
    if (Y < 0)
        sy++;
    X = abs(X);
    Y = abs(Y);

    vector<int> v;
    while (X > 0 || Y > 0) {
        if ((X & Y & 1) ||
            ((X | Y) & 1) == 0) {
            //! 最下位bitがどちらも1 or どちらも0
            return "IMPOSSIBLE";
        }

        if (X & 1) {
            if (Y == 0 && X == 1) {
                v.push_back(2);
                X--;
            }
            else if (((X + 1) ^ Y) & 2) {
                v.push_back(0);
                X++;
            }
            else {
                v.push_back(2);
                X--;
            }
        }
        else if (Y & 1) {
            if (X == 0 && Y == 1) {
                v.push_back(3);
                Y--;
            }
            else if ((X ^ (Y + 1)) & 2) {
                v.push_back(1);
                Y++;
            }
            else {
                v.push_back(3);
                Y--;
            }
        }

        X >>= 1LL;
        Y >>= 1LL;
    }

    string ret = "";
    REP(i, v.size()) {
        if (v[i] % 2 == 0) {
            ret.push_back(C[(v[i] + 2 * sx) % 4]);
        }
        else {
            ret.push_back(C[(v[i] + 2 * sy) % 4]);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll X, Y;
        cin >> X >> Y;
        cout << "Case #" << q + 1 << ": " << solve(X, Y) << endl;
    }
    return 0;
}