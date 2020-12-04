#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A;
    ll z = 0;
    ll p = 0, m = 0;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a == 0)
            z++;
        else
            A.push_back(a);

        if (a < 0)
            m += -a;
        if (a > 0)
            p += a;

    }
    if (m > p)
        sort(A.begin(), A.end());
    else
        sort(A.begin(), A.end(), greater<ll>());
    vector<ll> B;
    ll s = 0;
    REP(i, A.size()) {
        s += A[i];
        if (s == 0)
            break;

        B.push_back(A[i]);
    }

    if (s == 0) {
        cout << "NO" << endl;
        return;
    }

    while (z > 0) {
        z--;
        B.push_back(0);
    }
    cout << "YES" << endl;
    REP(i, N) {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}