#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll s = 0;
    REP(i, N) {
        cin >> S[i];
        s += S[i];
    }

    if (s % 10 != 0) {
        cout << s << endl;
        return 0;
    }

    ll mn = INF;
    REP(i, N) {
        if (S[i] % 10 == 0)
            continue;
        mn = std::min(mn, S[i]);
    }

    cout << std::max(0LL, s - mn) << endl;
    return 0;
}