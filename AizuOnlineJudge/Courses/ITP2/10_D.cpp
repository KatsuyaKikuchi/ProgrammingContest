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
        bit |= x;
    }

    void clear(ll x) {
        bit &= ~x;
    }

    void flip(ll x) {
        bit ^= x;
    }

    ll all(ll x) {
        if (count() == 64)
            return 1;
        return 0;
    }

    ll any(ll x) {
        if (count(x) == 0)
            return 0;
        return 1;
    }

    ll none(ll x) {
        if (count(x) == 0)
            return 1;
        return 0;
    }

    ll count(ll x) {
        ll ret = 0;
        REP(i, 64) {
            ret += (((bit & x) >> i) & 1);
        }
        return ret;
    }

    unsigned long long int val(unsigned long long int x) const {
        return bit & x;
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
        ll q, x;
        cin >> q >> x;
        if (q == 0) {
            cout << bit.test(x) << endl;
        }
        else if (q == 1) {
            bit.set(x);
        }
        else if (q == 2) {
            bit.clear(x);
        }
        else if (q == 3) {
            bit.flip(x);
        }
        else if (q == 4) {
            cout << bit.all(x) << endl;
        }
        else if (q == 5) {
            cout << bit.any(x) << endl;
        }
        else if (q == 6) {
            cout << bit.none(x) << endl;
        }
        else if (q == 7) {
            cout << bit.count(x) << endl;
        }
        else {
            cout << bit.val(x) << endl;
        }
    }
    return 0;
}