#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    ll H, N;
    cin >> H >> N;
    ll s = 0;
    REP(i, N) {
        cin >> A[i];
        s += A[i];
    }

    if (s >= H)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}