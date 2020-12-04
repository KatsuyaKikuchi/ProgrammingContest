#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll query(ll a, ll b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    ll ret;
    cin >> ret;
    return ret;
}

void result(vector<ll> &v) {
    cout << "! ";
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    vector<ll> A(N, -1);
    ll mx = 0;
    FOR(i, N, 1) {
        ll a = query(i, mx);
        ll b = query(mx, i);

        if (a > b) {
            A[i] = a;
        }
        else {
            A[mx] = b;
            mx = i;
        }
    }
    A[mx] = N;

    result(A);
    return 0;
}