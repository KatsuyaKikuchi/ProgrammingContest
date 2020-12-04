#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll A[200005];
ll F[200005];

bool check(ll n) {
    ll k = 0;
    REP(i, N) {
        if (A[i] * F[i] <= n)
            continue;
        ll p = n / F[i];
        k += A[i] - p;
    }
    return k <= K;
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
    sort(A, A + N, greater<ll>());
    sort(F, F + N);

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