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
    vector<bool> v(N + X + 5, false);

    REP(i, N) {
        cin >> A[i];
        v[A[i]] = true;
    }

    ll ret = 1;
    while (true) {
        if (!v[ret]) {
            X--;
        }
        if (X < 0)
            break;
        ret++;
    }
    return ret - 1;
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