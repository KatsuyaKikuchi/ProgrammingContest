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
struct SegementTree {
    using F = function<T(T, T)>;

    SegementTree(F func, T id)
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
            node[i] = merge(node[(1 << i) | 0], node[(1 << i) | 1]);
        }
    }

    void set(int n, T value) {
        int index = n + offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right)
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

int main() {
    ll N;
    cin >> N;
    auto func = [](ll a, ll b) { return std::min(a, b); };
    SegementTree<ll> seg(func, (1LL << 31) - 1);
    seg.init(N);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            seg.set(x, y);
        }
        else {
            cout << seg.get(x, y) << endl;
        }
    }
    return 0;
}