#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(ll index, const vector<ll> &A) {
    ll N = A.size();
    if (index < 0 || index >= N)
        return 0;
    if (index == 0) {
        if (N == 1)
            return A[index];
        if (A[index] > A[index + 1])
            return A[index];
        return 0;
    }
    if (index == N - 1) {
        if (A[index] > A[index - 1])
            return A[index];
        return 0;
    }

    if (A[index - 1] < A[index] && A[index] > A[index + 1])
        return A[index];
    if (A[index - 1] > A[index] && A[index] < A[index + 1])
        return -A[index];
    return 0;
}

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll sum = 0;
    REP(i, N) {
        sum += calc(i, A);
    }

    cout << sum << endl;
    REP(_, Q) {
        ll L, R;
        cin >> L >> R;
        L--;
        R--;
        vector<ll> v{L - 1, L, L + 1, R - 1, R, R + 1};
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        REP(i, v.size()) {
            sum -= calc(v[i], A);
        }

        swap(A[L], A[R]);
        REP(i, v.size()) {
            sum += calc(v[i], A);
        }
        cout << sum << endl;
    }
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