#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[10];
ll B[4] = {0, 10, 100, 1000};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }

    FOR(n, B[N], B[N - 1]) {
        bool e = true;
        vector<ll> v(N);
        ll m = n;
        REP(i, N) {
            v[N - 1 - i] = m % 10;
            m /= 10;
        }
        REP(i, M) {
            if (v[A[i].first - 1] != A[i].second)
                e = false;
        }
        if (e) {
            cout << n << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}