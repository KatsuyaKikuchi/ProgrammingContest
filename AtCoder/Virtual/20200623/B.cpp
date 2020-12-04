#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(ll R, ll C, ll a, ll b) {
    if (a == 0)
        return b;
    if (a == R)
        return R + C + (C - b);
    if (b == C)
        return C + a;
    return 2 * C + R + (R - a);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C, N;
    cin >> R >> C >> N;
    vector<pll> E;
    REP(i, N) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a != 0 && a != R && b != 0 && b != C)
            continue;
        if (c != 0 && c != R && d != 0 && d != C)
            continue;
        ll x = calc(R, C, a, b);
        ll y = calc(R, C, c, d);
        E.push_back(pll(min(x, y), max(x, y)));
    }
    N = E.size();
    sort(E.begin(), E.end(), [](pll a, pll b) { return a.second < b.second; });

    std::stack<pll> s;
    REP(i, N) {
        pll e = E[i];
        while (!s.empty()) {
            pll t = s.top();
            if (t.second < e.first)
                break;
            if (t.first < e.first && e.first < t.second) {
                cout << "NO" << endl;
                return 0;
            }
            s.pop();
        }
        s.push(e);
    }
    cout << "YES" << endl;
    return 0;
}