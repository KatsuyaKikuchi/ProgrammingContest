#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[100005];
ll A[100005];

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
    ll mh = 0;
    REP(i, N) {
        cin >> H[i];
        mh = std::max(mh, H[i]);
    }
    memset(A, 0, sizeof(A));
    {
        SegmentTree<ll> seg([](ll a, ll b) { return std::max(a, b); }, -1);
        seg.init(mh + 2);
        REP(i, N) {
            ll mi = seg.get(H[i] + 1, mh);
            A[i] += i - mi - 1;
            seg.set(H[i], i);
        }
    }
    {
        SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, N);
        seg.init(mh + 2);
        for (ll i = N - 1; i >= 0; --i) {
            ll mi = seg.get(H[i] + 1, mh);
            A[i] += mi - i - 1;
            seg.set(H[i], i);
        }
    }

    REP(i, N) {
        cout << A[i] << endl;
    }
    return 0;
}