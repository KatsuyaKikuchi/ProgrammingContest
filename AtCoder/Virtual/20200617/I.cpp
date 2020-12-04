#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll V[55];
bool U[55];

ll cmb(ll n, ll r) {
    ll ret = 1;
    memset(U, 0, sizeof(U));
    REP(i, r) {
        ret *= (n - i);
        REP(j, r) {
            if (U[j + 1])
                continue;
            if (ret % (j + 1) == 0) {
                U[j + 1] = true;
                ret /= (j + 1);
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    REP(i, N) {
        cin >> V[i];
    }
    sort(V, V + N, greater<ll>());
    ll s = 0;
    REP(i, A) {
        s += V[i];
    }

    pll mx(s, A);
    FOR(i, B, A) {
        s += V[i];
        if (mx.first * (A + 1 + i) < s * mx.second)
            mx = pll(s, A + 1 + i);
    }

    cout << OF64 << (double) (mx.first) / (double) (mx.second) << endl;
    ll cnt = 0;
    ll num = 0;
    REP(i, N) {
        if (V[i] == V[mx.second - 1]) {
            cnt++;
            if (i < mx.second)
                num++;
        }
    }

    ll ans = 0;
    s = mx.first;
    FOR(i, B + 1, mx.second) {
        if (mx.first * i == s * mx.second) {
            ans += cmb(cnt, num);
        }
        num++;
        s += V[i];
    }
    cout << ans << endl;
    return 0;
}