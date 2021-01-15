#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll N, D;
    cin >> N >> D;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    bool e = true;
    REP(i, N) {
        if (A[i] > D)
            e = false;
    }
    if (e)
        return true;
    REP(i, N) {
        FOR(j, N, i + 1) {
            if (A[i] + A[j] <= D)
                return true;
        }
    }
    return false;
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