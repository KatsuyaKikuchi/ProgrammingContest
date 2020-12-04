#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }
    ll ret = 0;
    REP(i, N) {
        ll n = 0;
        ll m = 0;
        ll index = 0;
        while (index < M) {
            if (S[i][index] == '*') {
                index++;
                continue;
            }
            if (index + 1 < M && S[i][index + 1] == '.') {
                m++;
                index++;
            }
            else
                n++;
            index++;
        }

        ret += std::min(X * n + Y * m, (n + 2 * m) * X);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}