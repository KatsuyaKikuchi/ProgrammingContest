#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];

int main() {
    ll N, K, Q;
    cin >> N >> K >> Q;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = INF;
    REP(i, N) {
        ll a = A[i];
        //! a未満の数字は入らないようにする
        priority_queue<ll, vector<ll>, greater<ll>> q0, q1;
        REP(j, N) {
            if (A[j] < a) {
                while (!q0.empty())
                    q0.pop();
                continue;
            }
            q0.push(A[j]);
            if (q0.size() == K) {
                ll t = q0.top();
                q0.pop();
                q1.push(t);
            }
        }

        if (q1.size() < Q)
            continue;
        ll min = INF, max = -INF;
        REP(j, Q) {
            ll m = q1.top();
            q1.pop();
            min = std::min(min, m);
            max = std::max(max, m);
        }
        ans = std::min(ans, max - min);
    }
    cout << ans << endl;
    return 0;
}