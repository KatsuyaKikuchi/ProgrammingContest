#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll max = -1;
    ll left = 0;
    ll p = 0;
    FOR(i, N, 1) {
        if (i >= K) {
            ll index = i - K + 1;
            if (A[index] > A[index - 1] && A[index] > A[index + 1])
                p--;
        }

        if (i + 1 >= K && p + 1 > max) {
            max = p + 1;
            left = i - K + 2;
        }

        if (i < N - 1) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1])
                p++;
        }
    }

    cout << max << " " << left << endl;
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