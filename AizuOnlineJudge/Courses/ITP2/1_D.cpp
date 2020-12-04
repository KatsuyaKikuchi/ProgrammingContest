#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int A[1005][500005];
ll I[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;


    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 0) {
            ll t, x;
            cin >> t >> x;
            A[t][I[t]++] = x;
        }
        else if (q == 1) {
            ll t;
            cin >> t;
            REP(i, I[t]) {
                cout << A[t][i];
                if (i < I[t] - 1)
                    cout << " ";
            }
            cout << endl;
        }
        else {
            ll t;
            cin >> t;
            I[t] = 0;
        }
    }
    return 0;
}