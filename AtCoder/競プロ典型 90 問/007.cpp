#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    A.push_back(-INF);
    A.push_back(INF);
    sort(A.begin(), A.end());
    N = A.size();
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll b;
        cin >> b;
        ll idx = lower_bound(A.begin(), A.end(), b) - A.begin();
        cout << std::min(abs(A[idx - 1] - b), std::abs(A[idx] - b)) << endl;
    }

    return 0;
}