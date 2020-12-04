#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    priority_queue<pll, vector<pll>> q;
    REP(i, N) {
        q.push(pll(B[i], i));
    }

    ll ans = 0;
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (B[t.second] <= A[t.second])
            continue;
        ll left = B[(t.second - 1 + N) % N];
        ll right = B[(t.second + 1) % N];
        ll s = left + right;
        ll n = std::min((t.first - std::max(left, right) + s - 1) / s,
                        (t.first - A[t.second] + s - 1) / s);
        ans += n;
        B[t.second] = t.first - n * s;
        if (B[t.second] <= 0)
            break;
        q.push(pll(B[t.second], t.second));
    }

    REP(i, N) {
        if (A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}