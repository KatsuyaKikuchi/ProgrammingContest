#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll s = 0;
    REP(i, N) {
        s += A[i];
        if (s == X) {
            if (i < N - 1)
                swap(A[i], A[i + 1]);
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}