#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve(vector<ll> &A) {
    ll N = A.size();
    REP(i, N - 1) {
        ll d = abs(A[i] - A[i + 1]);
        if (d % 2 == 1)
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
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        if (solve(A))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}