#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll B[200005];
ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> B[i];
    }

    ll max = 0;
    REP(i, N) {
        A[i] = B[i] + max;
        max = std::max(max, A[i]);
    }

    REP(i, N) {
        cout << A[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}