#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool A[100005][55];
ll B[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, Q;
    cin >> N >> M >> Q;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    REP(i, Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll n;
            cin >> n;
            n--;
            ll s = 0;
            REP(j, M) {
                if (A[n][j])
                    s += N - B[j];
            }
            cout << s << endl;
            continue;
        }
        ll n, m;
        cin >> n >> m;
        n--;
        m--;
        A[n][m] = true;
        B[m]++;
    }
    return 0;
}