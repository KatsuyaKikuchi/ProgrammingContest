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
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll sa = 0, sb = 0;
    REP(i, N) {
        cin >> A[i];
        sa += A[i];
    }
    REP(i, N) {
        cin >> B[i];
        sb += B[i];
    }

    ll M = sb - sa;
    REP(i, N) {
        ll n = A[i] - B[i];
        if (n >= 0)
            M -= n;
        else if (abs(n) % 2 == 1)
            M--;
    }

    if (M >= 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}