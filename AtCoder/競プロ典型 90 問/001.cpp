#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, L, K;
ll A[100005];

bool check(ll x) {
    ll num = 0;
    ll len = 0;
    REP(i, N - 1) {
        len += A[i + 1] - A[i];
        if (len >= x) {
            num++;
            len = 0;
        }
    }
    return num >= K + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> L >> K;
    A[0] = 0;
    REP(i, N) {
        cin >> A[i + 1];
    }
    A[N + 1] = L;
    N += 2;

    ll ans = 0, ng = L + 1;
    while (abs(ng - ans) > 1) {
        ll mid = (ng + ans) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}