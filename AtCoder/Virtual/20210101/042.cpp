#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, Q;
struct Shape {
    ll x, r, h;
};

Shape S[105];
double T[200005];

double calc() {
    ll A, B;
    cin >> A >> B;
    return T[B] - T[A];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    REP(i, N) {
        cin >> S[i].x >> S[i].r >> S[i].h;
    }
    T[0] = 0;
    FOR(i, 20005, 1) {
        REP(j, N) {
            if (S[j].x >= i)
                continue;
            double h0 = S[j].h;
            double r0 = S[j].r;
            double h1 = std::max(0.0, S[j].x + h0 - i);
            double r1 = r0 * h1 / h0;
            double s = M_PI * (r0 * r0 * h0 - r1 * r1 * h1) / 3.0;
            T[i] += s;
        }
    }
    REP(_, Q) {
        cout << OF64 << calc() << endl;
    }
    return 0;
}