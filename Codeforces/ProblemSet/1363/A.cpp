#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll N, X;
    cin >> N >> X;
    ll odd = 0, even = 0;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a % 2 == 1)
            odd++;
        else
            even++;
    }
    if (odd == 0)
        return false;
    odd--;
    X--;
    while (odd >= 2 && X >= 2) {
        odd -= 2;
        X -= 2;
    }
    return X <= even;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}