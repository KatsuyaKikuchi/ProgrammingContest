#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    ll ans = 0;
    REP(bit, 30) {
        ll t = pow(2LL, bit);
        ll mask = 2LL * t - 1;
        vector<ll> a(N), b(N);
        REP(i, N) {
            a[i] = (A[i] & mask);
            b[i] = (B[i] & mask);
        }
        sort(a.begin(), a.end());
        ll cnt = 0;
        REP(i, N) {
            ll bb = b[i];
            {
                // t <= x <= 2*t-1
                ll under = lower_bound(a.begin(), a.end(), t - bb) - a.begin();
                ll top = upper_bound(a.begin(), a.end(), 2LL * t - 1 - bb) - a.begin();
                cnt += top - under;
            }
            {
                // 2*t+t <= x <= 4*t
                ll under = lower_bound(a.begin(), a.end(), 3LL * t - bb) - a.begin();
                ll top = upper_bound(a.begin(), a.end(), 4LL * t - bb) - a.begin();
                cnt += top - under;
            }
        }
        if (cnt % 2 == 1)
            ans |= t;
    }
    cout << ans << endl;
    return 0;
}