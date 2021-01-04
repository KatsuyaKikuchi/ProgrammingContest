#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll A[200005], F[200005];

bool check(ll m) {
    ll num = 0;
    REP(i, N) {
        ll ok = A[i], ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if ((A[i] - mid) * F[i] <= m)
                ok = mid;
            else
                ng = mid;
        }
        num += ok;
    }
    return num <= K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> F[i];
    }
    sort(A, A + N);
    sort(F, F + N, greater<ll>());
    ll ans = INF, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}