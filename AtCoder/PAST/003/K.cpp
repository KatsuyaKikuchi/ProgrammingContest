#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Container {
    ll nxt = -1;
    ll bottom = -1;
    ll table = -1;
};

Container C[200005];
ll T[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        T[i] = i;
        C[i].bottom = i;
        C[i].table = i;
    }
    REP(i, Q) {
        ll x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        c--;
        ll top = -1;
        {
            //! desk x
            top = T[x];
            ll b = C[c].bottom;
            if (b == c)
                b = -1;
            T[x] = b;

            if (b >= 0)
                C[b].nxt = -1;
        }
        {
            //! desk y
            ll t = T[y];
            if (t >= 0) {
                C[t].nxt = c;
                C[c].bottom = t;
            }
            else {
                C[c].bottom = c;
                C[c].table = y;
            }
            T[y] = top;
        }

#if false
        REP(i, N) {
            cout << T[i] << " ";
        }
        cout << endl;
#endif
    }

    REP(i, N) {
        if (C[i].bottom != i)
            continue;
        ll table = C[i].table;
        ll nxt = C[i].nxt;
        while (nxt >= 0) {
            C[nxt].table = table;
            nxt = C[nxt].nxt;
        }
    }

    REP(i, N) {
        cout << C[i].table + 1 << endl;
    }
    return 0;
}