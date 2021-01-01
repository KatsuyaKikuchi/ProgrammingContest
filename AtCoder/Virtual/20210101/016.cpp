#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> q;
    for (ll i = N; i > 0; --i) {
        for (ll j = A.size() - 1; j >= 0; --j) {
            if (A[j] == j + 1) {
                q.push_back(j + 1);
                A.erase(A.begin() + j);
                break;
            }
        }
    }

    if (q.size() != N) {
        cout << -1 << endl;
        return 0;
    }
    reverse(q.begin(), q.end());
    REP(i, q.size()) {
        cout << q[i] << endl;
    }
    return 0;
}