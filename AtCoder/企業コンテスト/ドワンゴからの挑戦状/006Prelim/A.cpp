#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[55];
ll T[55];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i] >> T[i];
    }
    string X;
    cin >> X;
    ll ans = 0;
    bool sleep = false;
    REP(i, N) {
        if (sleep)
            ans += T[i];
        if (S[i] == X)
            sleep = true;
    }
    cout << ans << endl;
    return 0;
}