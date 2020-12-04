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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    if (N % 2 == 1) {
        if (A[N / 2] != B[N / 2])
            return false;
    }
    map<pll, ll> T;
    REP(i, N / 2) {
        ll a = A[i], b = A[N - 1 - i];
        T[pll(std::min(a, b), std::max(a, b))]++;
    }
    REP(i, N / 2) {
        ll a = std::min(B[i], B[N - 1 - i]), b = std::max(B[i], B[N - 1 - i]);
        pll p = pll(a, b);
        if (T[p]-- == 0)
            return false;
    }

    return true;
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