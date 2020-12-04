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
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<ll>());
    ll a = 0, b = 0;
    REP(i, N - 1) {
        if (A[i] == A[i + 1]) {
            if (a == 0) {
                a = A[i];
                i += 1;
            }
            else {
                b = A[i];
                break;
            }
        }
    }
    cout << a * b << endl;

    return 0;
}