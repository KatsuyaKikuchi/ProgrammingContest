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
    ll A;
    string B;
    cin >> A >> B;
    ll C = 0;
    REP(i, B.size()) {
        if (B[i] == '.')
            continue;
        C = C * 10 + (B[i] - '0');
    }

    ll X = (A * C) / 100LL;
    cout << X << endl;
    return 0;
}