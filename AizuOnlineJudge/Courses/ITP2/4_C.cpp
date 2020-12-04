#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll b, e, t;
        cin >> b >> e >> t;
        REP(i, e - b) {
            swap(A[b + i], A[t + i]);
        }
    }

    REP(i, N) {
        cout << A[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}