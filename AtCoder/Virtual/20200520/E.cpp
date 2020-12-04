#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    REP(left, K + 1) {
        REP(right, K + 1) {
            if (left + right > K || left + right > N)
                break;
            priority_queue<ll, vector<ll>, greater<ll>> q;
            ll s = 0;
            REP(i, left) {
                s += A[i];
                q.push(A[i]);
            }
            REP(i, right) {
                s += A[N - 1 - i];
                q.push(A[N - 1 - i]);
            }

            ans = std::max(ans, s);
            ll k = K - (left + right);
            while (!q.empty() && k > 0) {
                ll t = q.top();
                q.pop();
                s -= t;
                ans = std::max(ans, s);
                k--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}