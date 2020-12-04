#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct myBitset {
    myBitset()
            : bit(0) {
    }

    ll test(ll x) {
        return (bit >> x) & 1;
    }

    void set(ll x) {
        bit |= (1LL << x);
    }

    void clear(ll x) {
        bit &= ~(1LL << x);
    }

    void flip(ll x) {
        if ((bit >> x) & 1)
            bit &= ~(1LL << x);
        else
            bit |= 1LL << x;
    }

    ll all() {
        if (count() == 64)
            return 1;
        return 0;
    }

    ll any() {
        if (bit == 0)
            return 0;
        return 1;
    }

    ll none() {
        if (bit == 0)
            return 1;
        return 0;
    }

    ll count() {
        ll ret = 0;
        REP(i, 64) {
            ret += ((bit >> i) & 1);
        }
        return ret;
    }

    unsigned long long int val() {
        return bit;
    }

    unsigned long long int bit;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    myBitset bit;
    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 0) {
            ll x;
            cin >> x;
            cout << bit.test(x) << endl;
        }
        else if (q == 1) {
            ll x;
            cin >> x;
            bit.set(x);
        }
        else if (q == 2) {
            ll x;
            cin >> x;
            bit.clear(x);
        }
        else if (q == 3) {
            ll x;
            cin >> x;
            bit.flip(x);
        }
        else if (q == 4) {
            cout << bit.all() << endl;
        }
        else if (q == 5) {
            cout << bit.any() << endl;
        }
        else if (q == 6) {
            cout << bit.none() << endl;
        }
        else if (q == 7) {
            cout << bit.count() << endl;
        }
        else {
            cout << bit.val() << endl;
        }
    }
    return 0;
}