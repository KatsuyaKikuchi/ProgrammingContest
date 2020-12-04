#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
bool U[200005];

struct Query {
    ll t;
    ll x;
    ll y;
};

Query Q[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, q;
    cin >> N >> q;
    vector<ll> A(N);
    memset(U, 0, sizeof(U));
    REP(i, N) {
        A[i] = i + 1;
    }
    REP(i, q) {
        cin >> Q[i].t >> Q[i].x >> Q[i].y;
        Q[i].x--;
        Q[i].y--;
    }

    vector<ll> v;
    std::set<pll> S;
    for (ll i = q - 1; i >= 0; --i) {
        if (Q[i].t == 2) {
            S.insert(pll(Q[i].x + 1, Q[i].y - 1));
            continue;
        }
        pll p(Q[i].x, Q[i].x);
        auto s = S.lower_bound(p);
        if (s == S.end() || s->first > p.first) {
            U[Q[i].x] = true;
        }
        else {
            if (U[Q[i].x] || U[Q[i].x + 1]) {
            }
            else {
                continue;
            }
        }
        v.push_back(Q[i].x);
    }

    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        swap(A[v[i]], A[v[i] + 1]);
    }

    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}