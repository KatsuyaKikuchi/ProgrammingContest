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
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    sort(A, A + N, greater<ll>());
    sort(B, B + M, greater<ll>());

    ll index = 0;
    REP(i, M) {
        if (index < 0 || A[index] < B[i]) {
            cout << "NO" << endl;
            return 0;
        }
        index++;
    }

    cout << "YES" << endl;
    return 0;
}