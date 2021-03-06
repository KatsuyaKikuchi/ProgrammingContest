#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a > b; });
    vector<ll> count(N + 5, 0);
    REP(i, M) {
        count[A[i]]++;
    }
    REP(i, count.size()) {
        if (count[i] == 0)
            q.push(i);
    }
    ll ans = M + 1;
    if (!q.empty()) {
        ans = std::min(ans, q.top());
    }
    FOR(i, N, M) {
        ll last = A[i];
        ll first = A[i - M];
        count[first]--;
        count[last]++;
        if (count[first] == 0) {
            q.push(first);
        }
        while (!q.empty()) {
            ll t = q.top();
            if (count[t] == 0)
                break;
            q.pop();
        }

        if (q.empty()) {
            ans = std::min(ans, M + 1);
        }
        else {
            ans = std::min(ans, q.top());
        }
    }
    cout << ans << endl;
    return 0;
}