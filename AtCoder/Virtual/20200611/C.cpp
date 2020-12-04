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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;
    REP(i, N) {
        cin >> A[i];
    }
    ll index = -1;
    REP(i, N - 1) {
        if (A[i] + A[i + 1] >= L)
            index = i + 1;
    }

    if (index < 0) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        for (ll i = 1; i < index; ++i)
            cout << i << endl;
        for (ll i = N - 1; i > index; --i)
            cout << i << endl;
        cout << index << endl;
    }

    return 0;
}