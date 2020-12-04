#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll A, B, N, M;
    cin >> A >> B >> N >> M;
    if (N + M > A + B)
        return false;

    if (A > B) {
        ll d = std::min(N, A - B);
        N -= d;
        A -= d;
    }
    else if (A < B) {
        ll d = std::min(N, B - A);
        N -= d;
        B -= d;
    }
    if (std::max(A, B) >= N && std::min(A, B) >= M)
        return true;

    if (A == B) {
        ll d = std::min(M, B);
        M -= d;
        B -= d;
        if (M > 0)
            return false;

        if (A + B >= N)
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
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}