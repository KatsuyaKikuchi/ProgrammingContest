#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(ll n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const vector<T> &v) {
        int n = static_cast<int>(v.size());
        init(n);
        for (int i = 0; i < n; ++i) {
            node[offset + i] = v[i];
        }
        for (int i = offset - 1; i >= 0; --i) {
            node[i] = merge(node[(i << 1) | 0], node[(i << 1) | 1]);
        }
    }

    void set(int index, T value) {
        index += offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right]
    T get(int left, int right) {
        left += offset;
        right += offset + 1;

        T val = identity;
        while (left < right) {
            if (left & 1)
                val = merge(val, node[left++]);
            if (right & 1)
                val = merge(val, node[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    T identity;
    F merge;
    vector<T> node;
    int offset;
};

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

struct Query {
    ll index;
    ll a;
    ll b;
    ll result;
};
ll A[300005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    vector<Query> Q(M);
    REP(i, M) {
        cin >> Q[i].a >> Q[i].b;
        Q[i].b = N - 1 - Q[i].b;
        Q[i].index = i;
    }

    SegmentTree<ll> seg0([](ll a, ll b) { return a + b; }, 0);
    SegTree<pll, ll> seg1(N + 5, [](pll a, pll b) {
                              if (a.second < b.second)
                                  return a;
                              return b;
                          },
                          [](pll &a, ll b) { a.second += b; },
                          [](ll &a, ll b) { a += b; },
                          pll(INF, INF), 0);
    seg0.init(N + 5);
    sort(Q.begin(), Q.end(), [](Query a, Query b) { return a.a > b.a; });
    {
        ll s = Q[0].a;
        FOR(i, N, Q[0].a) {
            if (s < A[i]) {
                if (i + 1 < A[i]) {
                    s++;
                    continue;
                }
                seg0.set(i, 1);
                continue;
            }
            ll dist = s + 1 - A[i];
            s++;
            seg1.set(i, pll(i, dist));
        }
        Q[0].result = seg0.get(Q[0].a, Q[0].b);
    }
    FOR(i, Q.size(), 1) {
        ll s = Q[i].a;
        ll sum = 0;
        FOR(j, Q[i - 1].a, Q[i].a) {
            if (s < A[j]) {
                if (j + 1 < A[j]) {
                    s++;
                    continue;
                }
                seg0.set(j, 1);
                sum++;
                continue;
            }
            ll dist = A[j] + 1 - s;
            s++;
            seg1.set(i, pll(i, dist));
        }
        seg1.update(Q[i - 1].a, N, -sum);
        while (true) {
            pll t = seg1.get(Q[i].a, N);
            if (t.second > 0)
                break;
            seg0.set(t.first, 1);
            seg1.set(t.first, pll(INF, INF));
            seg1.update(t.first, N, -1);
        }
        Q[i].result = seg0.get(Q[i].a, Q[i].b);
    }

    sort(Q.begin(), Q.end(), [](Query a, Query b) { return a.index < b.index; });
    REP(i, M) {
        cout << Q[i].result << endl;
    }

    return 0;
}