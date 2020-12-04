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
    while (true) {
        bool exist = false;
        for (ll i = N - 1; i > 0; --i) {
            if (A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                num++;
                exist = true;
            }
        }
        if (!exist)
            break;
    }

    REP(i, N - 1) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
    cout << num << endl;
    return 0;
}