#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll A[100005];
ll B[100005];

bool solve() {
    sort(A, A + N);
    sort(B, B + M);
    if (M > N)
        return false;
    ll idx = 0;
    REP(i, M) {
        while (idx < N && A[idx] < B[i]) {
            idx++;
        }
        if (idx >= N)
            return false;
        idx++;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }


    if (solve())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}