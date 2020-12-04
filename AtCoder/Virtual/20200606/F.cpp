#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll A[100005];
ll S[100005];

ll solve(ll n, ll x) {
    ll ok = -1, ng = N;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (n + A[mid] >= x)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

bool check(ll x) {
    ll cnt = 0;
    REP(i, N) {
        cnt += solve(A[i], x) + 1;
    }
    return cnt <= M;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<ll>());

    ll mx = A[0] + A[0] + 1, ng = 1;
    while (abs(mx - ng) > 1) {
        ll mid = (mx + ng) / 2;
        if (check(mid))
            mx = mid;
        else
            ng = mid;
    }

    memset(S, 0, sizeof(S));
    REP(i, N) {
        S[i] += A[i];
        S[i + 1] += S[i];
    }

    ll ans = 0;
    ll cnt = 0;
    REP(i, N) {
        ll index = solve(A[i], mx);
        if (index < 0)
            continue;
        ans += A[i] * (index + 1) + S[index];
        cnt += index + 1;
    }
    cout << ans + (M - cnt) * (mx - 1) << endl;

    return 0;
}