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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    bool m = false;
    bool p = false;
    for (ll i = 0; i < N; ++i) {
        ll d = B[i] - A[i];
        if (d > 0 && !p)
            return false;
        if (d < 0 && !m)
            return false;
        if (A[i] < 0)
            m = true;
        if (A[i] > 0)
            p = true;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}