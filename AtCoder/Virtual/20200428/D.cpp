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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a < b; });
    REP(i, N) {
        ll a;
        cin >> a;
        q.push(a);
    }
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + M, [](pll a, pll b) { return a.second > b.second; });
    REP(i, M) {
        REP(j, A[i].first) {
            q.push(A[i].second);
        }
        if (q.size() > 2 * N)
            break;
    }

    ll ans = 0;
    REP(i, N) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}