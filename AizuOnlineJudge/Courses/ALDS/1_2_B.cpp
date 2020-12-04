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

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll num = 0;
    REP(i, N) {
        ll mi = i;
        FOR(j, N, i + 1) {
            if (A[j] < A[mi])
                mi = j;
        }
        if (mi != i)
            num++;
        swap(A[i], A[mi]);
    }

    REP(i, N - 1) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
    cout << num << endl;
    return 0;
}