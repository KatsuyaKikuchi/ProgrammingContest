#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve(vector<pll> &A) {
    ll N = A.size();
    if (A[0].first < A[0].second)
        return false;
    REP(i, N - 1) {
        ll d0 = A[i + 1].first - A[i].first;
        ll d1 = A[i + 1].second - A[i].second;
        if (d0 < 0 || d1 < 0)
            return false;
        if (d0 < d1)
            return false;

        if (A[i + 1].first < A[i + 1].second)
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
        ll N;
        cin >> N;
        vector<pll> A(N);
        REP(i, N) {
            cin >> A[i].first >> A[i].second;
        }

        if (solve(A))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}