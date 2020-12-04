#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll m) {
    ll ret = 1;
    ll r = n;
    while (m > 0) {
        if (m & 1)
            ret = ret * r % MOD;
        r = r * r % MOD;
        m >>= 1;
    }
    return ret;
}

ll A[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X, Y;
    cin >> N >> X >> Y;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    if (X == 1) {
        REP(i, N) {
            cout << A[i] << endl;
        }
        return 0;
    }
    while (A[0] * X < A[N - 1]) {
        A[0] *= X;
        //cout << A[0] << endl;
        sort(A, A + N);
        Y--;
        if (Y == 0)
            break;
    }
    ll p = Y / N;
    Y %= N;
    queue<ll> q;
    REP(i, N) {
        q.push(A[i] % MOD);
        //cout << A[i] << endl;
    }
    REP(i, Y) {
        ll t = q.front();
        q.pop();
        q.push((t * X) % MOD);
    }

    REP(i, N) {
        ll t = q.front();
        q.pop();
        cout << t * modpow(X, p) % MOD << endl;
    }
    return 0;
}