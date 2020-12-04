#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[30];
bool dp[100000];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    ll max = 0;
    REP(i, N) {
        for (ll j = max; j >= 0; --j) {
            if (dp[j])
                dp[j + A[i]] = true;
            max = std::max(max, j + A[i]);
        }
    }

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll q;
        cin >> q;
        if (dp[q])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}