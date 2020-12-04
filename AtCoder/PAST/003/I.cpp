#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll R[100005];
ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        R[i] = i;
        C[i] = i;
    }
    bool rot = false;
    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 3) {
            rot = !rot;
        }
        else if (q == 1) {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            if (!rot)
                swap(R[a], R[b]);
            else
                swap(C[a], C[b]);
        }
        else if (q == 2) {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            if (!rot)
                swap(C[a], C[b]);
            else
                swap(R[a], R[b]);
        }
        else {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;

            if (rot)
                swap(a, b);
            ll r = R[a];
            ll c = C[b];

            cout << N * r + c << endl;
        }

#if false
        cout << "--------------" << endl;
        REP(i, N) {
            REP(j, N) {
                ll r = R[i], c = C[j];
                if (rot) {
                    r = R[j];
                    c = C[i];
                }
                cout << N * r + c << " ";

            }
            cout << endl;
        }
#endif
    }
    return 0;
}