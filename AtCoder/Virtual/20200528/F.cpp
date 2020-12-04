#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    memset(T, 0, sizeof(T));
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second < b.second; });
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q0([](pll a, pll b) { return a.second > b.second; });
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q1([](pll a, pll b) { return a.second < b.second; });
    REP(i, N) {
        pll p;
        cin >> p.first >> p.second;
        p.first--;
        q.push(p);
    }

    ll type = 0;
    ll sum = 0;
    REP(i, K) {
        pll t = q.top();
        q.pop();
        if (T[t.first]++ == 0)
            type++;
        else
            q0.push(t);
        sum += t.second;
    }

    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (T[t.first]++ == 0)
            q1.push(t);
    }

    ll ans = sum + type * type;
    while (!q1.empty() && !q0.empty()) {
        pll t = q1.top();
        q1.pop();
        pll s = q0.top();
        q0.pop();

        sum = sum - s.second + t.second;
        type++;
        ans = std::max(ans, sum + type * type);
    }

    cout << ans << endl;
    return 0;
}