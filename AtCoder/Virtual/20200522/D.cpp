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
    pll s, t;
    cin >> s.first >> s.second;
    cin >> t.first >> t.second;
    string S = "", T = "";
    t.first -= s.first;
    t.second -= s.second;
    REP(i, abs(t.first)) {
        S.push_back('R');
        T.push_back('L');
    }
    REP(i, abs(t.second)) {
        S.push_back('U');
        T.push_back('D');
    }

    cout << S << T;
    cout << "DR" << S << "UL" << "UL" << T << "DR" << endl;

    return 0;
}