#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<ll> X(N);
    vector<SegmentTree<ll>> segs;
    REP(i, 30) {
        SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
        seg.init(N + 5);
        segs.push_back(seg);
    }
    REP(i, N) {
        ll idx = S[i] - 'a';
        X[i] = idx;
        segs[idx].set(i, 1);
    }
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll idx;
            char c;
            cin >> idx >> c;
            idx--;
            ll n = c - 'a';
            segs[X[idx]].set(idx, 0);
            X[idx] = n;
            segs[X[idx]].set(idx, 1);
        }
        else {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll n = 0;
            REP(i, 27) {
                if (segs[i].get(l, r) > 0)
                    n++;
            }
            cout << n << endl;
        }
    }
    return 0;
}