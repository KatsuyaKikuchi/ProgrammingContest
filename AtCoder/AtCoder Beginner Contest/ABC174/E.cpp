#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double lld;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll A[200005];

bool check(ll n) {
    ll num = 0;
    REP(i, N) {
        ll t = A[i];

        num += t / n;
        t %= n;
        if (t == 0)
            num--;
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

    ll ans = INF, ng = 0;
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