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

struct Data {
    pll d;
    ll index;
};
ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    SegmentTree<pll> seg1([](pll a, pll b) {
        if (a.first > b.first)
            return a;
        return b;
    }, pll(0, 0));
    SegmentTree<Data> seg2([](Data a, Data b) {
                               if (std::max(a.d.first, a.d.second) > std::max(b.d.first, b.d.second))
                                   return a;
                               return b;
                           },
                           Data{pll(0, 0), 0});

    seg1.init(N);
    seg2.init(N);
    vector<queue<ll>> q(N);
    REP(i, N) {
        ll k;
        cin >> k;
        REP(j, k) {
            ll n;
            cin >> n;
            q[i].push(n);
        }
    }
    REP(i, N) {
        A[i] = q[i].front();
        q[i].pop();
        seg1.set(i, pll(A[i], i));
        pll p(A[i], 0);
        if (!q[i].empty())
            p.second = q[i].front();
        seg2.set(i, Data{p, i});

    }
    ll M;
    cin >> M;
    REP(i, M) {
        ll n;
        cin >> n;
        ll index;
        if (n == 1) {
            pll t = seg1.get(0, N - 1);
            cout << t.first << endl;
#if false
            cout << t.first << " " << t.second << endl;
#endif
            index = t.second;
            A[index] = 0;
            if (!q[index].empty()) {
                A[index] = q[index].front();
                q[index].pop();
            }
        }
        else {
            Data d = seg2.get(0, N - 1);
            ll m = std::max(d.d.first, d.d.second);
            cout << m << endl;

#if false
            cout << d.d.first << " " << d.d.second << " " << d.index << endl;
#endif
            index = d.index;
            if (A[index] == m) {
                A[index] = q[index].empty() ? 0 : q[index].front();
            }
            if (!q[index].empty())
                q[index].pop();
        }
        seg1.set(index, pll(A[index], index));
        pll p(A[index], 0);
        if (!q[index].empty())
            p.second = q[index].front();
        seg2.set(index, Data{p, index});
    }
    return 0;
}