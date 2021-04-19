#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 7;
const ll INF = (ll) 1e15;

char C[2] = {'T', 'A'};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S, X;
    cin >> S >> X;

    ll c = 0;
    vector<bool> U(10, false);
    U[0] = true;
    ll p = 1;
    REP(i, N) {
        ll m = (S[N - 1 - i] - '0') * p % MOD;
        if (X[N - 1 - i] != C[c]) {
            c = (c + 1) % 2;
            REP(j, U.size()) {
                U[j] = !U[j];
            }
        }
        vector<bool> u(10, false);
        REP(j, U.size()) {
            u[j] = u[j] || U[j] || U[(j + m) % 7];
        }
        swap(U, u);
        p = p * 10 % MOD;
    }

    bool aoki = false;
    if (C[c] == 'T') {
        if (!U[0])
            aoki = true;
    }
    else {
        if (U[0])
            aoki = true;
    }

    if (aoki)
        cout << "Aoki" << endl;
    else
        cout << "Takahashi" << endl;
    return 0;
}