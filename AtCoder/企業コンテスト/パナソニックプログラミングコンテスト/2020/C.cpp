#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


string solve(ll A, ll B, ll C) {
    if (C - (A + B) < 0)
        return "No";

    ll t = 4 * A * B;
    ll s = (C - (A + B)) * (C - (A + B));
    if (t < s)
        return "Yes";
    return "No";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    cout << solve(A, B, C) << endl;
    return 0;
}