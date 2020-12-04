#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
bool U[100005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i];
    }
    memset(U, 0, sizeof(U));

    vector<ll> v;
    REP(i, M) {
        ll t = A[M - 1 - i];
        if (U[t - 1])
            continue;
        U[t - 1] = true;
        v.push_back(t);
    }

    REP(i, N) {
        if (U[i])
            continue;
        v.push_back(i + 1);
    }

    REP(i, N) {
        cout << v[i] << endl;
    }
    return 0;
}