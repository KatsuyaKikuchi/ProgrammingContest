#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[500005];

struct Data {
    pll range = pll(INF, 0);
    ll count = 0;
};

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

    vector<Data> D(N + 1);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
        D[A[i]].range.first = std::min(D[A[i]].range.first, i);
        D[A[i]].range.second = std::max(D[A[i]].range.second, i);
        D[A[i]].count++;
    }
    SegmentTree<ll> seg([](ll a, ll b) { return std::max(a, b); }, 0);
    SegmentTree<ll> right([](ll a, ll b) { return std::max(a, b); }, 0);
    seg.init(N + 5);
    right.init(N + 5);
    REP(i, N) {
        if (D[A[i]].range.second != i)
            continue;
        ll m = seg.get(0, D[A[i]].range.first);
        seg.set(D[A[i]].range.second, m + D[A[i]].count);
    }

    ll ans = N - seg.get(0, N - 1);

    for (ll i = N - 1; i > 0; --i) {
        ll r = right.get(A[i], A[i]) + 1;
        ll m = seg.get(0, i - 1);
        ans = std::min(ans, i + 1 - m + (N - (i + 1) - r));
        right.set(A[i], r);
    }
    cout << ans << endl;
    return 0;
}