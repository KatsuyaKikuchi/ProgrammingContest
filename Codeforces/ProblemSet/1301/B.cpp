#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9 + 1;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll max = -1, min = INF;
    ll m = 0;
    REP(i, N - 1) {
        if ((A[i] != -1 && A[i + 1] == -1) ||
            (A[i] == -1 && A[i + 1] != -1)) {
            max = std::max({max, A[i], A[i + 1]});
            min = std::min(std::max(A[i], A[i + 1]), min);
        }

        if (A[i] != -1 && A[i + 1] != -1)
            m = std::max(m, abs(A[i] - A[i + 1]));
    }

    ll b = (max + min) / 2;
    ll a = std::max({m, abs(max - b), abs(min - b)});
    if (max == -1)
        a = 0;
    cout << a << " " << b << endl;
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