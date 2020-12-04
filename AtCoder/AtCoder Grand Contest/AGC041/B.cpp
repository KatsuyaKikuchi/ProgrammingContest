#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M, V, P;
ll A[100005];

//! スコアがn以上のものをp個以内に抑えることができる？
bool check(ll n) {
    ll m = M * V;
    vector<ll> v;
    REP(i, N) {
        v.push_back(A[i]);
    }

    REP(i, P - 1) {
        v[i] += M;
        m -= M;
    }
    FOR(i, N, P) {
        if (m > 0) {
            m -= std::min(M, std::max(n - A[i], 0LL));
        }
    }
    m = std::max(m, 0LL);
    return v[P - 1] + m <= n;
}

int main() {
    cin >> N >> M >> V >> P;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });

    ll ok = INF, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    //! okまでは大丈夫
    ll ans = 0;
    REP(i, N) {
        if (A[i] + M >= ok)
            ans++;
    }
    cout << ans << endl;
    return 0;
}