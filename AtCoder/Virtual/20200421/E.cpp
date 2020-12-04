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

bool check(ll n) {
    ll s = M * (V - 1);
    vector<ll> v(N, 0);
    REP(i, N) {
        if (i == n)
            continue;
        ll m = std::min({M, s, std::max(0LL, A[n] + M - A[i])});
        v[i] += m;
        s -= m;
    }
    for (ll i = N - 1; i >= 0; --i) {
        if (i == n)
            continue;
        ll m = std::min(s, M);
        m = std::min(m, M - v[i]);
        v[i] += m;
        s -= m;
    }
    ll p = 0;
    REP(i, N) {
        if (i == n)
            continue;
        if (v[i] + A[i] > A[n] + M)
            p++;
    }
    return p < P;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> V >> P;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    ll ans = N - 1, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << N - ans << endl;
    return 0;
}