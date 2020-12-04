#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll A[105];

void out() {
    REP(i, N - 1) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    out();
    FOR(i, N, 1) {
        ll v = A[i];
        ll j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        out();
    }
    return 0;
}