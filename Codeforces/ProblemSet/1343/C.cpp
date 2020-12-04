#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &A) {
    ll N = A.size();
    A.push_back(-A[N - 1]);
    ll ret = 0;
    ll n = 0, m = -INF;
    REP(i, N + 1) {
        if (A[i] > 0) {
            if (m > -INF)
                ret += m;
            m = -INF;
            n = std::max(n, A[i]);
        }
        if (A[i] < 0) {
            ret += n;
            n = 0;
            m = std::max(m, A[i]);
        }
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
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(A) << endl;
    }
    return 0;
}