#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    if (N == 2) {
        return A[0] == A[1];
    }
    vector<ll> L(N + 1, 0), R(N + 1, 0);
    REP(i, N) {
        L[i + 1] = A[i] - L[i];
        if (L[i + 1] < 0)
            L[i + 1] = INF;
    }
    for (ll i = N - 1; i >= 0; --i) {
        R[i] = A[i] - R[i + 1];
        if (R[i] < 0)
            R[i] = INF;
    }
    if (L[N] == 0)
        return true;


    REP(i, N - 1) {
        //! iとi+1をスワップする
        ll left = L[i];
        ll right = R[i + 2];
        if (left == INF && right == INF)
            break;
        ll a = A[i];
        ll b = A[i + 1];
        b -= left;
        a -= right;
        if (b < 0 || a < 0)
            continue;
        if (a == b)
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}