#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    cin >> M;
    REP(i, M) {
        cin >> B[i];
    }

    vector<ll> v;
    REP(i, N) {
        auto it = lower_bound(B, B + M, A[i]);
        if (A[i] != *it)
            v.push_back(A[i]);
    }
    REP(i, M) {
        auto it = lower_bound(A, A + N, B[i]);
        if (B[i] != *it)
            v.push_back(B[i]);
    }
    sort(v.begin(), v.end());
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}