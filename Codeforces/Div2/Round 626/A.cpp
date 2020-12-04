#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(vector<ll> &A) {
    ll N = A.size();
    REP(i, N) {
        ll s = 0;
        FOR(j, N, i) {
            s += A[j];
            if (s % 2 == 0) {
                cout << j - i + 1 << endl;
                for (ll n = i; n <= j; ++n) {
                    cout << n + 1;
                    if (n < j)
                        cout << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
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
        solve(A);
    }
    return 0;
}