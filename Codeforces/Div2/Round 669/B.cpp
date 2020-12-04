#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> B(N);
    vector<bool> U(N);
    ll index = 0;
    REP(i, N) {
        if (A[index] < A[i])
            index = i;
    }
    B[0] = A[index];
    U[index] = true;

    ll g = B[0];
    FOR(i, N, 1) {
        ll p = -1;
        REP(j, N) {
            if (U[j])
                continue;
            if (p < 0 || gcd(g, A[p]) < gcd(g, A[j]))
                p = j;
        }
        U[p] = true;
        B[i] = A[p];
        g = gcd(g, A[p]);
    }

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