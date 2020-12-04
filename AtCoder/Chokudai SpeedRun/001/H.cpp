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
    ll N;
    cin >> N;
    REP(i, N + 1) {
        B[i] = INF;
    }
    REP(i, N) {
        cin >> A[i];
        ll index = lower_bound(B, B + N + 1, A[i]) - B;
        B[index] = A[i];
    }

    {
        ll index = lower_bound(B, B + N + 1, INF) - B;
        cout << index << endl;
    }
    return 0;
}