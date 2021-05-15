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
    vector<ll> A(3);
    REP(i, 3) {
        cin >> A[i];
    }
    vector<ll> v{0, 1, 2};
    do {
        ll a0 = v[0], a1 = v[1], a2 = v[2];
        if (A[a2] - A[a1] == A[a1] - A[a0]) {
            cout << "Yes" << endl;
            return 0;
        }

    } while (next_permutation(v.begin(), v.end()));
    cout << "No" << endl;
    return 0;
}