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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll a = 0, b = 0;
    REP(i, N) {
        if (A[i] == 0)
            a++;
        else
            b++;
    }
    if (b <= a) {
        cout << a << endl;
        REP(i, a) {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    if (b % 2 == 1)
        b--;

    cout << b << endl;
    REP(i, b) {
        cout << 1 << " ";
    }
    cout << endl;
    return;
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