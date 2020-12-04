#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(20)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll G[15];

int main() {
    pll g;
    cin >> g.first >> g.second;
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> G[i].first >> G[i].second;
    }

    double min = INF;
    REP(i, N) {
        pll v0 = G[i];
        pll v1 = G[(i + 1) % N];

        pll a(g.first - v0.first, g.second - v0.second);
        pll b(v1.first - v0.first, v1.second - v0.second);

        double la = sqrt(a.first * a.first + a.second * a.second);
        double lb = sqrt(b.first * b.first + b.second * b.second);

        double theta = acos((double) (a.first * b.first + a.second * b.second) /
                            (la * lb));

        min = std::min(min, la * sin(theta));

    }
    cout << OF64 << min << endl;
    return 0;
}