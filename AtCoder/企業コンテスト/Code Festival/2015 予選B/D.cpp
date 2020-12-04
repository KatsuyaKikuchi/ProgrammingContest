#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

std::set<pll> S;

ll solve(ll x, ll c) {
    ll s = x;
    while (c > 0) {
        auto it = S.lower_bound(pll(x, x));
        if ((--it)->second < x)
            it++;
        if (it == S.end()) {
            x += c;
            c = 0;
            continue;
        }
        if (x >= it->first)
            x = it->second + 1;
        s = std::min(s, it->first);
        ll d = std::max(0LL, std::min(c, it->first - x));
        c -= d;
        x += d;

        if (c > 0) {
            x = it->second + 1;
            S.erase(it);
        }
    }
    S.insert(pll(s, x - 1));
#if false
    for (auto it = S.begin(); it != S.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "-----------" << endl;
#endif
    return x - 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    S.insert(pll(-1, -1));
    vector<ll> ans(N);
    REP(i, N) {
        ll x, c;
        cin >> x >> c;
        ans[i] = solve(x, c);
    }

    REP(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}