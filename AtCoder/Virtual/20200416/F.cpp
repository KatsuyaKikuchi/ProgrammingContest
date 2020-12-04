#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];
ll U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K, N;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A, A + N, [](pll a, pll b) { return a.second > b.second; });
    memset(U, 0, sizeof(U));
    ll ans = 0;

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    ll k = 0;
    ll x = 0;

    ll sum = 0;
    REP(i, N) {
        k++;
        if (k <= K) {
            sum += A[i].second;
            U[A[i].first]++;
            if (U[A[i].first] > 1) {
                q.push(A[i]);
            }
            else {
                x++;
            }
            ans = std::max(ans, sum + x * x);
            continue;
        }

        if (U[A[i].first] > 0)
            continue;

        if (!q.empty()) {
            pll t = q.top();
            q.pop();
            sum = sum - t.second + A[i].second;
            U[A[i].first]++;
            x++;
            ans = std::max(ans, sum + x * x);
        }
    }

    cout << ans << endl;

    return 0;
}