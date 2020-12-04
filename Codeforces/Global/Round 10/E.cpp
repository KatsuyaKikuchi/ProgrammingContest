#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[30][30];

void result(vector<pll> &v) {
    REP(i, v.size()) {
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
    }
}

ll input() {
    ll K;
    cin >> K;
    return K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    memset(A, 0, sizeof(A));

    ll s = 0;
    for (ll i = 1; i < N; i += 2) {
        ll t = pow(25LL, i / 2) ;
        FOR(j, N, 0) {
            A[i][j] = t;
            t++;
        }
    }
    REP(i, N) {
        REP(j, N) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}