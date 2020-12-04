#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

template<class Monoid, class Action>
struct SegTree {
    using FuncMonoid = function<Monoid(Monoid, Monoid)>;
    using FuncAction = function<void(Monoid &, Action)>;
    using FuncLazy = function<void(Action &, Action)>;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid UNITY_MONOID;
    Action UNITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;

    SegTree() {}

    SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy)
            : FM(fm), FA(fa), FL(fl), UNITY_MONOID(unity_monoid), UNITY_LAZY(unity_lazy) {
        SIZE = 1;
        HEIGHT = 0;
        while (SIZE < n)
            SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }

    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &unity_monoid, const Action &unity_lazy) {
        FM = fm;
        FA = fa;
        FL = fl;
        UNITY_MONOID = unity_monoid;
        UNITY_LAZY = unity_lazy;
        SIZE = 1;
        HEIGHT = 0;
        while (SIZE < n)
            SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }

    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
    }

    /* update [a, b) */
    inline void evaluate(int k) {
        if (lazy[k] == UNITY_LAZY)
            return;
        if (k < SIZE)
            FL(lazy[k * 2], lazy[k]), FL(lazy[k * 2 + 1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = UNITY_LAZY;
    }

    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k * 2, l, (l + r) >> 1), update(a, b, v, k * 2 + 1, (l + r) >> 1, r);
            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }

    /* get [a, b) */
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k * 2, l, (l + r) >> 1), get(a, b, k * 2 + 1, (l + r) >> 1, r));
        else
            return UNITY_MONOID;
    }

    inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }

    inline Monoid operator[](int a) { return get(a, a + 1); }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE; ++i) {
            cout << (*this)[i];
            if (i != SIZE)
                cout << ",";
        }
        cout << endl;
    }
};

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll P[200005];

ll sum(ll a, ll n) {
    ll ret = a * P[n] % MOD;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;

    P[1] = 1;
    FOR(i, N + 3, 1) {
        P[i + 1] = (P[i] * 10LL + 1) % MOD;
    }

    vector<pll> A(N);
    REP(i, N) {
        A[i] = pll(1, 1);
    }

    auto fm = [](pll a, pll b) {
        //cout << "debug" << a.first << "+" << b.first << endl;
        ll p = (a.first * modpow(10LL, b.second) % MOD + b.first) % MOD;
        return pll(p, a.second + b.second);
    };
    auto fa = [](pll &a, long long d) {
        if (d == 0) {
            // return;
        }
        a.first = sum(d, a.second);
    };
    auto fl = [](long long &d, long long e) { d = e; };
    SegTree<pll, ll> seg(N + 2, fm, fa, fl, pll(0, 0), 0);
    REP(i, N) {
        seg.set(i, pll(1, 1));
    }
    seg.build();

    REP(_, Q) {
        ll L, R, D;
        cin >> L >> R >> D;
        seg.update(L - 1, R, D);
        cout << seg.get(0, N).first << endl;

#if false
        REP(i, N) {
            cout << seg.get(i, i + 1).first << endl;
        }
        cout << endl;
        cout << "----------------------" << endl;
#endif
    }
    return 0;
}