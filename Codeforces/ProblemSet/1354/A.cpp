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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (B < A && C <= D)
        return -1;
    if (A <= B)
        return B;

    ll d = A - B;
    ll c = C - D;
    ll ret = B + C * ((d + c - 1) / c);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << solve() << endl;
    }
    return 0;
}