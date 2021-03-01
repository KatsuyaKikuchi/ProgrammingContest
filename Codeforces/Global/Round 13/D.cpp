#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll a, b;
    cin >> a >> b;
    // a->b
    if (a > b)
        return false;
    if (a == b)
        return true;

    vector<ll> av, bv;
    while (a > 0) {
        av.push_back(a % 2);
        a /= 2;
    }
    while (b > 0) {
        bv.push_back(b % 2);
        b /= 2;
    }
    ll ac = 0, bc = 0;
    REP(i, av.size()) {
        ac += av[i];
    }
    REP(i, bv.size()) {
        bc += bv[i];
    }
    if (ac < bc)
        return false;
    while (av.size() < bv.size()) {
        av.push_back(0);
    }
    ll N = av.size();
    ll t = 0;
    REP(i, N) {
        t += av[i];
        t -= bv[i];
        if (t < 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}