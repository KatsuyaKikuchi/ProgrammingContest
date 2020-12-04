#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> v;
    v.push_back(A[0]);
    FOR(i, N - 1, 1) {
        ll a = A[i + 1] - A[i];
        ll b = A[i] - A[i - 1];
        if (a * b < 0)
            v.push_back(A[i]);
    }
    v.push_back(A[N - 1]);
    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}