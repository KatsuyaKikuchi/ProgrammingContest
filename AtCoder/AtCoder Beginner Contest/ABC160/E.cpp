#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[100005];
ll Q[100005];
ll R[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    REP(i, A) {
        cin >> P[i];
    }
    REP(i, B) {
        cin >> Q[i];
    }
    REP(i, C) {
        cin >> R[i];
    }
    sort(P, P + A, greater<ll>());
    sort(Q, Q + B, greater<ll>());
    sort(R, R + C, greater<ll>());

    priority_queue<ll, vector<ll>> q0;
    priority_queue<ll, vector<ll>> q1;
    REP(i, X) {
        q0.push(P[i]);
    }
    REP(i, Y) {
        q0.push(Q[i]);
    }
    REP(i, std::min(X + Y, C)) {
        q1.push(R[i]);
    }
    ll ans = 0;
    REP(i, X + Y) {
        ll a = q0.top();
        ll b = 0;
        if (!q1.empty())
            b = q1.top();

        if (a > b) {
            ans += a;
            q0.pop();
        }
        else {
            ans += b;
            q1.pop();
        }
    }
    cout << ans << endl;
    return 0;
}