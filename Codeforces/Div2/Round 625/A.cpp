#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];
ll B[105];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    ll a = 0, b = 0;
    REP(i, N) {
        if (A[i] < B[i])
            b++;
        else if (A[i] > B[i])
            a++;
    }

    if (a == 0)
        cout << -1 << endl;
    else {
        cout << b / a + 1 << endl;
    }
    return 0;
}