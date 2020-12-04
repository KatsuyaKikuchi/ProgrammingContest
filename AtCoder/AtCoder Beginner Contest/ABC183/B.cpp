#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A == C) {
        cout << A << endl;
        return 0;
    }
    D = -D;
    double a = (D - B) / (C - A);
    double b = -A * a + B;
    double x = -b / a;
    cout << OF64 << x << endl;
    return 0;
}