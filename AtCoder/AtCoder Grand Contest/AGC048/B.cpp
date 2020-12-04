#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    ll ans = 0;
    priority_queue<ll> q0, q1;
    REP(i, N) {
        ans += A[i];
        ll d = B[i] - A[i];
        if (i % 2 == 0)
            q0.push(d);
        else
            q1.push(d);
    }

    while (!q0.empty() && !q1.empty()) {
        ll d = q0.top() + q1.top();
        q0.pop();
        q1.pop();
        if (d < 0)
            break;
        ans += d;
    }
    cout << ans << endl;

    return 0;
}