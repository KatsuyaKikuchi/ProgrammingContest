#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[205];

void solve(ll N, vector<ll> &A) {
    memset(U, 0, sizeof(U));
    vector<ll> ans(2 * N);
    REP(i, N) {
        U[A[i]] = true;
        ans[2 * i] = A[i];
    }
    REP(i, N) {
        ll a = A[i];
        ll n = 2 * N + 1;
        for (ll j = a + 1; j <= 2 * N; ++j) {
            if (!U[j]) {
                n = j;
                break;
            }
        }
        ans[2 * i + 1] = n;
        U[n] = true;
    }

    REP(i, 2 * N) {
        if (!U[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }

    REP(i, ans.size()) {
        cout << ans[i];
        if (i < 2 * N - 1)
            cout << " ";
    }
    cout << endl;
    return;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        solve(N, A);
    }
    return 0;
}