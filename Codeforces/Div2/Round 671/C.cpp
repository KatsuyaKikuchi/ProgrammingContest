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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    bool e = true;
    ll n = 0;
    REP(i, N) {
        if (X != A[i]) {
            e = false;
            continue;
        }
        n++;
    }
    if (e)
        return 0;

    ll diff = 0;
    REP(i, N) {
        diff += X - A[i];
    }
    if (diff == 0 || n >= 2)
        return 1;
    if (n == 1) {
        ll sum = X + X + diff;
        if (abs(sum) % N == 0)
            return 1;
    }
    return 2;
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