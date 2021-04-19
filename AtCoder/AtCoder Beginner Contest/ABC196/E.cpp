#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll A[200005];
ll T[200005];

ll func(ll value, ll index) {
    if (T[index] == 1) {
        return value + A[index];
    }
    else if (T[index] == 2) {
        return std::max(value, A[index]);
    }
    return std::min(value, A[index]);
}

ll calc(ll value) {
    REP(i, N) {
        value = func(value, i);
    }
    return value;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> A[i] >> T[i];
    }

    ll low = calc(-INF);
    ll heigh = calc(INF);
    ll sum = 0;
    REP(i, N) {
        if (T[i] == 1)
            sum += A[i];
    }

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll x;
        cin >> x;
        cout << std::max(low, std::min(x + sum, heigh)) << endl;
    }
    return 0;
}