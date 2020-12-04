
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
    ll N;
    cin >> N;
    REP(i, N) {
        ll A, B;
        cin >> A >> B;
        if (A == B)
            cout << -1 << endl;
        else
            cout << abs(A - B) << endl;
    }
    return 0;
}