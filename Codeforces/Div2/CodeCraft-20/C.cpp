#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1000005];
ll B[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, P;
    cin >> N >> M >> P;
    REP(i, N) {
        cin >> A[i];
        A[i] %= P;
    }
    REP(i, M) {
        cin >> B[i];
        B[i] %= P;
    }

    ll ai = 0;
    ll bi = 0;
    REP(i, N) {
        if (A[i] != 0) {
            ai = i;
            break;
        }
    }
    REP(i, M) {
        if (B[i] != 0) {
            bi = i;
            break;
        }
    }

    cout << ai + bi << endl;
    return 0;
}