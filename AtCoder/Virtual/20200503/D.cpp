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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll n = 0;
    REP(i, N) {
        cin >> A[i];
        n = max(A[i], n);
    }
    sort(A, A + N);

    ll r = A[0];
    REP(i, N) {
        if (abs((n + 1) / 2 - r) > abs((n + 1) / 2 - A[i]))
            r = A[i];
    }
    cout << n << " " << r << endl;
    return 0;
}