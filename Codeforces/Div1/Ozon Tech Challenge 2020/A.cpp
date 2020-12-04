#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(vector<ll> &A, vector<ll> &B) {
    ll N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    REP(i, N) {
        cout << A[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    REP(i, N) {
        cout << B[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N), B(N);
        REP(i, N) {
            cin >> A[i];
        }
        REP(i, N) {
            cin >> B[i];
        }
        solve(A, B);
    }
    return 0;
}