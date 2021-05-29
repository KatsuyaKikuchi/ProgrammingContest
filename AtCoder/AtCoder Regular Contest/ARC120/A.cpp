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
    vector<ll> S(N + 3, 0);
    REP(i, N) {
        S[i] += A[i];
        S[i + 1] += S[i];
    }
    ll mx = 0;
    ll s = 0;
    REP(i, N) {
        mx = std::max(A[i], mx);
        cout << S[i] + (i + 1) * mx + s << endl;
        s += S[i];
    }
    return 0;
}