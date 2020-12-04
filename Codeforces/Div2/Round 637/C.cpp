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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> v(N);
    REP(i, N) {
        v[A[i] - 1] = i;
    }

    ll min = v[0];
    FOR(i, N, 1) {
        if (v[i] == v[i - 1] + 1)
            continue;

        if (min < v[i])
            return false;
        min = v[i];
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
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}