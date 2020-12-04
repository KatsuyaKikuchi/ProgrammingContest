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

ll A[1000010];
ll B[1000010];
bool U[1000010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(B, 0, sizeof(B));
    memset(U, 0, sizeof(U));
    REP(i, N) {
        cin >> A[i];
        B[A[i]]++;
    }

    ll g = A[0];
    REP(i, N) {
        g = gcd(g, A[i]);
    }
    if (g > 1) {
        cout << "not coprime" << endl;
        return 0;
    }

    for (ll i = 2; i < 1000005; ++i) {
        if (U[i])
            continue;
        ll m = 0;
        for (ll j = i; j < 1000005; j += i) {
            U[j] = true;
            m += B[j];
        }
        if (m > 1) {
            cout << "setwise coprime" << endl;
            return 0;
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}