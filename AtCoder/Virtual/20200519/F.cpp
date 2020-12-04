#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second < b.second; });
    REP(i, N) {
        pll a;
        cin >> a.first >> a.second;
        q.push(a);
    }

    ll sum = 0;
    ll type = 0;
    map<ll, ll> m;
    priority_queue<ll, vector<ll>, greater<>> q0;
    REP(i, K) {
        pll t = q.top();
        q.pop();
        sum += t.second;
        if (m[t.first]++ == 0)
            type++;
        else
            q0.push(t.second);
    }

    vector<pll> v;
    while (!q.empty() && !q0.empty()) {
        pll t0 = q.top();
        q.pop();
        if (m[t0.first]++ > 0)
            continue;
        ll t1 = q0.top();
        q0.pop();
        pll p(0, 0);
        if (v.size() > 0)
            p = v.back();
        p.first += t0.second;
        p.second += t1;
        v.push_back(p);
    }

    ll ans = sum + type * type;
    REP(i, v.size()) {
        ans = std::max(ans, sum - v[i].second + v[i].first + (type + 1 + i) * (type + 1 + i));
    }

    cout << ans << endl;
    return 0;
}