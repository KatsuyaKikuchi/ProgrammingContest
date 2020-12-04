#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll N, D;
ll R[3];
ll A[1000005];

ll solve(const vector<ll> &v) {
    ll ret = 0;
    ll index = 1;
    for (; index < v.size() - 1;) {
        ll a0 = v[index] * R[0] + R[2];
        ll b0 = R[1] + R[0];

        if (index + 1 < v.size()) {
            a0 += v[index + 1] * R[0] + R[2];
            b0 += R[1] + R[0];
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> R[0] >> R[1] >> R[2] >> D;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = D * (N - 1);
    vector<vector<ll>> v;
    vector<ll> t;
    REP(i, N) {
        ll a = A[i] * R[0] + R[2];
        ll b = R[1] + R[2];
        if (a <= b) {
            ans += a;
            if (t.size() > 0)
                v.push_back(t);
            t.clear();
            continue;
        }
        t.push_back(A[i]);
    }
    if (t.size() > 0)
        v.push_back(t);

    for (auto &v0:v) {
        ans += solve(v0);
    }

    cout << ans << endl;
    return 0;
}