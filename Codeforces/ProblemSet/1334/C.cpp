#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll solve(vector<pll> &A) {
    ll N = A.size();
    ll s = 0;
    REP(i, N) {
        s += std::max(0LL, A[(i + 1) % N].first - A[i].second);
    }

    ll ret = INF;
    REP(i, N) {
        ll t = s + A[i].first - std::max(0LL, A[i].first - A[(i - 1 + N) % N].second);
        ret = std::min(ret, t);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<pll> A(N);
        REP(i, N) {
            cin >> A[i].first >> A[i].second;
        }
        cout << solve(A) << endl;
    }
    return 0;
}