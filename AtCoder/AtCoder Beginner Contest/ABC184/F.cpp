#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[45];
ll dp[2000000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T;
    cin >> N >> T;
    REP(i, N) {
        cin >> A[i];
    }
    if (N == 1) {
        if (A[0] <= T)
            cout << A[0] << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    ll n = N / 2;
#if false
    if (N <= 20) {
        ll ans = 0;
        REP(b, pow(2LL, N)) {
            ll t = 0;
            REP(i, N) {
                if (((b >> i) & 1) == 1)
                    t += A[i];
            }
            if (t > T)
                continue;
            ans = std::max(t, ans);
        }
        cout << ans << endl;
        return 0;
    }
#endif
    vector<ll> d;
    REP(b, pow(2LL, n)) {
        ll t = 0;
        REP(i, n) {
            if (((b >> i) & 1) == 1)
                t += A[i];
        }
        if (t > T)
            continue;
        d.push_back(t);
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    REP(b, pow(2LL, N - n)) {
        ll t = 0;
        REP(i, N - n) {
            if (((b >> i) & 1) == 1) {
                t += A[n + i];
            }
        }
        if (t > T)
            continue;
        ans = std::max(ans, t);
        ll ok = -1, ng = d.size();
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (d[mid] + t <= T)
                ok = mid;
            else
                ng = mid;
        }
        if (ok >= 0)
            ans = std::max(t + d[ok], ans);
    }
    cout << ans << endl;

    return 0;
}