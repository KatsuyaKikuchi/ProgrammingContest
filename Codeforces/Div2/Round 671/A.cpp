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
    ll N;
    string S;
    cin >> N >> S;
    ll p = N % 2;
    if (p == 1) {
        REP(i, N) {
            if (i % 2 == 1)
                continue;
            if ((S[i] - '0') % 2 == 1)
                return 1;
        }
        return 2;
    }

    REP(i, N) {
        if (i % 2 == 0)
            continue;
        if ((S[i] - '0') % 2 == 0)
            return 2;
    }
    return 1;
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