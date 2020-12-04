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
    REP(i, N) {
        cin >> A[i];
    }

    B[0] = 0;
    REP(i, N - 1) {
        B[i + 1] = A[i] - B[i];
    }
    ll a = (A[N - 1] - B[N - 1]) / 2;

    REP(i, N) {
        ll x = B[i];
        if (i % 2 == 0)
            x += a;
        else
            x -= a;
        cout << 2 * x << " ";
    }
    cout << endl;
    return 0;
}