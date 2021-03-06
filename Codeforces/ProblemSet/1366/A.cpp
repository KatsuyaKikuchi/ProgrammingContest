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
    ll A, B;
    cin >> A >> B;
    if (A > B)
        swap(A, B);
    ll d = B - A;
    ll ret = std::max(0LL, A - d) / 3;
    A -= 3 * ret;
    B -= 3 * ret;
    ret *= 2;

    ret += std::min(A, B / 2);
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