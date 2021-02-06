#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    pll p;
    cin >> p.first >> p.second;
    string S;
    cin >> S;;
    ll N = S.length();
    pll g(0, 0);
    REP(i, N) {
        pll t = g;
        switch (S[i]) {
            case 'U':
                t.second++;
                break;
            case 'D':
                t.second--;
                break;
            case 'L':
                t.first--;
                break;
            case 'R':
                t.first++;
                break;
        }
        if (abs(p.first - t.first) <= abs(p.first - g.first) && abs(p.second - t.second) <= abs(p.second - g.second))
            g = t;
    }
    return p.first == g.first && p.second == g.second;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}