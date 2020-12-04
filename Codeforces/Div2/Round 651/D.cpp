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

bool check(ll x) {
    {
        //! odd <= x
        ll cnt = 0;
        REP(i, N) {
            if (cnt % 2 == 0 && A[i] <= x)
                cnt++;
            else if (cnt % 2 == 1)
                cnt++;
        }
        if (cnt >= K)
            return true;
    }
    {
        //! even <= x
        ll cnt = 0;
        REP(i, N) {
            if (cnt % 2 == 1 && A[i] <= x)
                cnt++;
            else if (cnt % 2 == 0)
                cnt++;
        }
        if (cnt >= K)
            return true;
    }
    return false;
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