#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

ll solve() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    if (N == 2)
        return -1;
    vector<ll> B(N);
    REP(i, N) {
        ll p = 1;
        while (p * 2LL <= A[i]) {
            p *= 2LL;
        }
        B[i] = p;
    }
    for (ll i = 1; i < N - 1; ++i) {
        if (B[i] == B[i + 1] && B[i] == B[i - 1])
            return 1;
    }
    ll ret = INF;
    REP(i, N - 1) {
        ll a = 0;
        for (ll left = i; left >= 0; left--) {
            a ^= A[left];
            ll b = 0;
            for (ll right = i + 1; right < N; right++) {
                b ^= A[right];
                if (a > b) {
                    ll num = (right - (i + 1)) + (i - left);
                    ret = std::min(ret, num);
                }
            }
        }
    }
    if (ret == INF)
        ret = -1;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}