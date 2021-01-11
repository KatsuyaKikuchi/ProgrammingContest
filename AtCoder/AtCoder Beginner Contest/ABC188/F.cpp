#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int64_t, int64_t> P;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

void chmin(ll &a, ll b) {
    a = min(a, b);
}

ll solve(ll X, ll Y) {
    if (X >= Y)
        return X - Y;
    ll ret = Y - X;

    priority_queue<P, vector<P>, greater<P>> q;
    map<ll, ll> memo;
    q.push(P(0, Y));
    auto insert = [&](int64_t v, int64_t n) {
        if (v < ret && (!memo.count(n) || v < memo[n])) {
            q.emplace(v, n);
            memo[n] = v;
        }
    };
    while (!q.empty()) {
        P t = q.top();
        q.pop();
        ll v = t.first, n = t.second;
        if (v >= ret)
            break;
        if (n <= 2e18 / 1)
            chmin(ret, v + abs(n - X));
        ll d = n % 2;
        {
            ll vv = v + d + 1;
            ll nn = n / 2;
            insert(vv, nn);
        }
        {
            ll vv = v + 2 - d + 1;
            ll nn = n / 2 + 1;
            insert(vv, nn);
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y;
    cin >> X >> Y;
    cout << solve(X, Y) << endl;
    return 0;
}