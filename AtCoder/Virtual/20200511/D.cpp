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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i];
        A[i]--;
    }

    vector<ll> v;
    REP(i, M) {
        ll a = A[M - 1 - i];
        if (U[a])
            continue;
        v.push_back(a);
        U[a] = true;
    }

    REP(i, N) {
        if (U[i])
            continue;
        v.push_back(i);
    }

    REP(i, N) {
        cout << v[i] + 1 << endl;
    }
    return 0;
}