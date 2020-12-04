#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Query {
    ll a, b;
    char c;
};

ll get(ll x) {
    ll p = 1;
    while (p * 2 < x) {
        p *= 2;
    }
    return p;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;
    vector<Query> q;
    ll y = x;
    ll p = get(x);
    ll r = 0;
    while (true) {
        ll s = y + y;
        q.push_back(Query{y, y, '+'});
        if ((s & p) == 0) {
            y = s;
            continue;
        }
        q.push_back(Query{s, x, '^'});
        ll t = s ^x;
        q.push_back(Query{t, s, '+'});
        t += s;
        q.push_back(Query{t, x, '^'});
        t ^= x;
        r = t;
        if (r == get(r))
            break;

    }

    y = x;
    while (y > 1) {
        if ((r & y) == 0) {
            q.push_back(Query{y, y, '+'});
            y = y + y;
            continue;
        }
        q.push_back(Query{y, r, '^'});
        y ^= r;
        if (y * 2LL == r) {
            r = y;
            if ((r & x) > 0) {
                q.push_back(Query{r, x, '^'});
                x ^= r;
            }
            y = x;
            continue;
        }
    }

    cout << q.size() << endl;
    REP(i, q.size()) {
        cout << q[i].a << " " << q[i].c << " " << q[i].b << endl;
    }
    return 0;
}