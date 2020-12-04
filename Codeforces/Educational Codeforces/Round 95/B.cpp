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
    vector<ll> A(N), L(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> L[i];
    }
    vector<ll> v;
    REP(i, N) {
        if (L[i] == 0)
            v.push_back(A[i]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll index = 0;
    REP(i, N) {
        if (L[i] == 0)
            A[i] = v[index++];
        cout << A[i] << " ";
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