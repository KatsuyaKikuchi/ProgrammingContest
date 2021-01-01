#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    REP(i, N) {
        S[i] += A[i];
        S[i + 1] += S[i];
    }
    for (ll i = N - 2; i >= 0; --i) {
        if (2LL * S[i] < A[i + 1]) {
            cout << N - i - 1 << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}