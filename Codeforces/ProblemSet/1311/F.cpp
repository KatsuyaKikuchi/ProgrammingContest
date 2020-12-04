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
            node[i] = merge(node[(1 << i) | 0], node[(1 << i) | 1]);
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

pll A[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first;
    }
    vector<ll> v;
    REP(i, N) {
        cin >> A[i].second;
        v.push_back(A[i].second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    SegmentTree<pll> seg([](pll a, pll b) { return pll(a.first + b.first, a.second + b.second); }, pll(0, 0));
    seg.init(v.size());
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });
    ll ans = 0;
    REP(i, N) {
        ll index = lower_bound(v.begin(), v.end(), A[i].second) - v.begin();
        pll t = seg.get(0, index);
        ans += t.first * A[i].first - t.second;
        pll s = seg.get(index, index);
        s.first++;
        s.second += A[i].first;
        seg.set(index, s);
    }
    cout << ans << endl;
    return 0;
}