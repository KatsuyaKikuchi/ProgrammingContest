#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, X, Y, Z;
ll A[100005];

bool check() {
    sort(A, A + N);
    vector<ll> v;
    REP(i, N) {
        ll m = (A[i] + 999) / 1000;
        ll z = std::min(m / 10, Z);
        Z -= z;
        m -= z * 10LL;
        v.push_back(m);
    }
    sort(v.begin(), v.end(), greater<ll>());
    REP(i, N) {
        ll m = v[i];
        ll z = std::min((m + 9) / 10, Z);
        Z -= z;
        m = std::max(0LL, m - z * 10);
        v[i] = m;
    }
    REP(i, N) {
        ll m = v[i];
        ll y = std::min(m / 5, Y);
        Y -= y;
        m -= y * 5LL;
        v[i] = m;
    }
    sort(v.begin(), v.end(), greater<ll>());
    REP(i, N) {
        ll m = v[i];
        ll z = std::min((m + 9) / 10, Z);
        Z -= z;
        m = std::max(0LL, m - z * 10);
        ll y = std::min((m + 4) / 5, Y);
        Y -= y;
        m = std::max(0LL, m - y * 5);
        ll x = std::min(X, m);
        X -= x;
        m -= x;
        if (m > 0)
            return false;
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X >> Y >> Z;
    REP(i, N) {
        cin >> A[i];
        if (A[i] % 1000 == 0)
            A[i]++;
    }
    if (check())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}