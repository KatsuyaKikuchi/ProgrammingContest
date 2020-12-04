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
    string S;
    cin >> S;
    vector<ll> v;
    ll p = 1;
    REP(i, S.length()) {
        if (S[i] == '+') {
            v.push_back(p);
            p = 1;
            continue;
        }
        if (S[i] == '*')
            continue;
        p = std::min(p * (S[i] - '0'), 1LL);
    }
    v.push_back(p);

    ll ans = 0;
    REP(i, v.size()) {
        if (v[i] > 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}