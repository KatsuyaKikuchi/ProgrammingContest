#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> v;
    for (ll i = 1; i * i <= sum; ++i) {
        if (sum % i != 0)
            continue;
        v.push_back(i);
        v.push_back(sum / i);
    }

    ll ans = 1;
    REP(i, v.size()) {
        vector<ll> u;
        ll s = 0;
        REP(j, N) {
            ll m = A[j] % v[i];
            u.push_back(m);
            s += (v[i] - m);
        }
        sort(u.begin(), u.end());
        ll t = 0;
        REP(j, N) {
            t += u[j];
            s -= (v[i] - u[j]);
            if (t == s) {
                if (t <= K)
                    ans = std::max(ans, v[i]);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}